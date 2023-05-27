#include "row_cards.hpp"


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


bool RowCards::move_card_in_stack(StackCards& stack)
{
	if (row_.empty())
	{
		return false;
	}

	const bool is_complete = stack.try_push_card(row_.back());
	if (is_complete)
	{
		row_.pop_back();
	}
	return is_complete;
}


bool RowCards::move_card_in_row(RowCards& new_row_card)
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

size_t RowCards::size() const noexcept
{
	return row_.size();
}

const std::vector<Card>& RowCards::get_date() const noexcept
{
	return  row_;
}