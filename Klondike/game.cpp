#include "game.hpp"
#include <cstdlib>
#include "console.hpp"
#include "exception.hpp"


Game::Game()
{
	stacks_cards_.emplace_back(Suit::clubs);
	stacks_cards_.emplace_back(Suit::diamonds);
	stacks_cards_.emplace_back(Suit::hearts);
	stacks_cards_.emplace_back(Suit::spades);

	rows_cards_.resize(7);



	view_.reset(new Console);
}

void Game::start_game()
{
	deck_.shuffle_deck();

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (deck_.empty())
			{
				throw deck_exception();
			}
			const Card card = deck_.pick_up_the_card();
			rows_cards_[i].add_card(card);
			deck_.delete_card();
		}
	}
}


bool Game::move_card_from_deck_to_stackcards(const size_t number_to_where)
{
	if (number_to_where >= 4)
	{
		return false;
	}

	if (deck_.empty())
	{
		return false;
	}

	const Card card = deck_.pick_up_the_card();

	if (stacks_cards_[number_to_where].push_card(card))
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
	if (number_to_where >= 7)
	{
		return false;
	}

	if (deck_.empty())
	{
		return false;
	}

	const Card card = deck_.pick_up_the_card();

	if (rows_cards_[number_to_where].push_card(card))
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
	if (number_from_where >= 7 || number_to_where >= 4)
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
	if (number_from_where >= 7 || number_to_where >= 4)
	{
		return false;
	}


	if (from_wich_card > rows_cards_[number_from_where].size())
	{
		return false;
	}

	return rows_cards_[number_from_where].move_card_in_row(rows_cards_[number_to_where]);
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

	size_t number = 0;
	for (auto row_cards : rows_cards_)
	{
		view_->draw_row_cards(number, row_cards);
		number++;
	}

	number = 0;
	for (auto stack_cards : stacks_cards_)
	{
		view_->draw_stack_cards(number, stack_cards);
		number++;
	}

	view_->draw_info(player_);
}