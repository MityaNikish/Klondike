#include "stack_cards.hpp"
#include "exception.hpp"

StackCards::StackCards(const Suit& suit_stack) : suit_stack_(suit_stack) {}


bool StackCards::push_card(const Card& card)
{
	if (suit_stack_ != card.get_suit())
	{
		return false;
	}

	if (stack_.empty())
	{
		if (card.get_rank() == Rank::ace)
		{
			stack_.push_back(card);
			return true;
		}
		return false;
	}

	if (stack_.back().get_rank() + 1 != card.get_rank())
	{
		return false;
	}

	stack_.push_back(card);
	return true;
}


Card StackCards::get_top() const
{
	if (stack_.empty())
	{
		throw stack_cards_exception();
	}

	return stack_.back();
}


bool StackCards::empty() const noexcept
{
	return stack_.empty();
}

std::vector<Card> StackCards::get_date() const noexcept
{
	return stack_;
}

Suit StackCards::get_suit() const noexcept
{
	return suit_stack_;
}