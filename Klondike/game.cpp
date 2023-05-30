#include "game.hpp"
#include <cstdlib>
#include "console.hpp"
#include "exception.hpp"
#include <random>
#include <ctime>

size_t const Game::count_stacks = 4;

size_t const Game::count_rows = 7;

Game::Game(const std::string& name_player) : rows_cards_(count_rows), player_(name_player)
{
	stacks_cards_.emplace_back(Suit::clubs);
	stacks_cards_.emplace_back(Suit::diamonds);
	stacks_cards_.emplace_back(Suit::hearts);
	stacks_cards_.emplace_back(Suit::spades);

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


bool Game::move_card_from_deck_to_stackcards(const IndexStack index_to)
{
	if (index_to.check_validity())
	{
		return false;
	}
	const size_t number_to_where = index_to.get_index();

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


bool Game::move_card_from_deck_to_rowcards(const IndexRow index_to)
{
	if (index_to.check_validity())
	{
		return false;
	}
	const size_t number_to_where = index_to.get_index();

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


bool Game::move_card_from_rowcards_to_stackcards(const IndexRow index_from, const IndexStack index_to)
{
	if (index_from.check_validity() || index_to.check_validity())
	{
		return false;
	}
	const size_t number_from_where = index_from.get_index();
	const size_t number_to_where = index_to.get_index();

	RowCards *row = &rows_cards_[number_from_where];
	StackCards *stack = &stacks_cards_[number_to_where];

	if (row->empty())
	{
		return false;
	}

	if (stack->try_push_card(row->get_back()))
	{
		row->pop_back();
		player_.add_point(10);
		return true;
	}
	player_.subtract_point(5);
	return false;
}


bool Game::move_card_from_rowcards_to_rowcards(const int count_cards, const IndexRow index_from, const IndexRow index_to)
{
	if (index_from.check_validity() || index_to.check_validity())
	{
		return false;
	}
	const size_t number_from_where = index_from.get_index();
	const size_t number_to_where = index_to.get_index();

	if (count_cards > rows_cards_[number_from_where].size() || count_cards < 0)
	{
		return false;
	}

	std::vector<Card> cards_from = rows_cards_[number_from_where].get_date();
	RowCards row_temp;

	bool complete = true;
	for (size_t index = cards_from.size() - 1 - count_cards; index < cards_from.size(); index++)
	{
		complete = row_temp.try_push_card(cards_from[index]);
		if (!complete)
		{
			return false;
		}
	}

	std::vector<Card> cards_temp = row_temp.get_date();
	RowCards* row_to = &rows_cards_[number_from_where];

	if (!row_to->try_push_card(cards_temp[0]))
	{
		return false;
	}

	for (size_t index = 1 ; index < count_cards; index++)
	{
		const bool temp = row_to->try_push_card(cards_from[index]);
	}

	RowCards* row_from = &rows_cards_[number_from_where];

	for (size_t index = 0; index < count_cards; index++)
	{
		row_from->pop_back();
	}

	return true;
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