#include "game.hpp"
#include <cstdlib>
#include "console.hpp"
#include "exception.hpp"
#include <random>
#include <ctime>

size_t const Game::count_stacks = 4;

size_t const Game::count_rows = 7;

Game::Game(const std::string& name_player) : player_(name_player)
{
	stacks_cards_.emplace_back(Suit::clubs);
	stacks_cards_.emplace_back(Suit::diamonds);
	stacks_cards_.emplace_back(Suit::hearts);
	stacks_cards_.emplace_back(Suit::spades);

	rows_cards_.resize(count_rows);

	view_.reset(new Console);
}

void Game::start_game()
{
	deck_.shuffle_deck(static_cast<int>(time(nullptr)));

	for (size_t i = 0; i < count_rows; i++)
	{
		for (size_t j = 0; j < i + 1; j++)
		{
			if (deck_.empty())
			{
				throw deck_exception();
			}
			const Card card = deck_.get_active_card();
			rows_cards_[i].add_card(card);
			deck_.delete_card();
		}
	}
}


bool Game::move_card_from_deck_to_stackcards(const size_t number_to_where)
{
	if (number_to_where >= count_stacks)
	{
		return false;
	}

	if (deck_.empty())
	{
		return false;
	}

	const Card card = deck_.get_active_card();

	if (stacks_cards_[number_to_where].try_push_card(card))
	{
		deck_.delete_card();
		player_.add_point(10);
		return true;
	}
	player_.subtract_point(5);
	return false;
}


bool Game::move_card_from_deck_to_rowcards(const size_t number_to_where)
{
	if (number_to_where >= count_rows)
	{
		return false;
	}

	if (deck_.empty())
	{
		return false;
	}

	const Card card = deck_.get_active_card();

	if (rows_cards_[number_to_where].try_push_card(card))
	{
		deck_.delete_card();
		player_.add_point(10);
		return true;
	}
	player_.subtract_point(5);
	return false;
}


bool Game::move_card_from_rowcards_to_stackcards(const size_t number_from_where, const size_t number_to_where)
{
	if (number_from_where >= count_rows || number_to_where >= count_stacks)
	{
		return false;
	}

	RowCards row_cards = rows_cards_[number_from_where];
	StackCards stack_cards = stacks_cards_[number_to_where];


	if (rows_cards_[number_from_where].move_card_in_stack(stacks_cards_[number_to_where]))
	{
		player_.add_point(10);
		return true;
	}
	player_.subtract_point(5);
	return false;

}


bool Game::move_card_from_rowcards_to_rowcards(const size_t from_wich_card, const size_t number_from_where, const size_t number_to_where)
{
	if (number_from_where >= count_rows || number_to_where >= count_stacks)
	{
		return false;
	}


	if (from_wich_card > rows_cards_[number_from_where].size())
	{
		return false;
	}

	return rows_cards_[number_from_where].try_move_card_in_row(rows_cards_[number_to_where]);
}


void Game::skip_card_desk()
{
	if (deck_.empty())
	{
		return;
	}

	deck_.next();
}


void Game::update_view() const
{
	view_->clear();

	view_->draw_deck(deck_);


	for (size_t number_row = 0; number_row < count_rows; number_row++)
	{
		view_->draw_row_cards(number_row, rows_cards_[number_row]);
	}

	for (size_t number_stack = 0; number_stack < count_stacks; number_stack++)
	{
		view_->draw_stack_cards(number_stack, stacks_cards_[number_stack]);
	}

	view_->draw_info(player_);
}