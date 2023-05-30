#include "row_cards.hpp"
#include "exception.hpp"


RowCards::RowCards() = default;


bool RowCards::try_push_card(const Card& card)
{
	if (row_.empty())
	{
		if (card.get_rank() != Rank::king)
		{
			return false;
		}
		row_.push_back(card);
		return true;
	}

	const Card prev_card = row_.back();

	if (!hitch_check(prev_card, card))
	{
		return false;
	}

	row_.push_back(card);
	return true;
}


void RowCards::add_card(const Card& card)
{
	row_.push_back(card);
}


bool RowCards::try_move_card_in_row(RowCards& new_row_card)
{
	if (row_.empty())
	{
		return false;
	}

	const bool is_complete = new_row_card.try_push_card(row_.back());
	if (is_complete)
	{
		row_.pop_back();
	}
	return is_complete;
}


bool RowCards::hitch_check(const Card& prev_card, const Card& card)
{
	if (prev_card.get_color() == card.get_color())
	{
		return false;
	}

	if (prev_card.get_rank() != card.get_rank() + 1)
	{
		return  false;
	}

	return  true;
}

void RowCards::pop_back()
{
	if (row_.empty())
	{
		throw row_cards_exception();
	}
	row_.pop_back();

}

Card RowCards::get_back() const
{
	if (row_.empty())
	{
		throw row_cards_exception();
	}
	return row_.back();
}

bool RowCards::empty() const noexcept
{
	return row_.empty();
}

size_t RowCards::size() const noexcept
{
	return row_.size();
}

const std::vector<Card>& RowCards::get_date() const noexcept
{
	return  row_;
}