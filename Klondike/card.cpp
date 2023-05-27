#include "card.hpp"
#include <vector>


Card::Card(const Suit suit, const Rank rank) : suit_(suit), rank_(rank)
{
	std::vector<Suit> black_suit = { spades, clubs };
	std::vector<Suit> red_suit = { diamonds, hearts };

	if (std::ranges::find(black_suit, suit) != black_suit.end())
	{
		color_ = Black;
	}

	if (std::ranges::find(red_suit, suit) != red_suit.end())
	{
		color_ = Red;
	}
}


Suit Card::get_suit() const noexcept
{
	return suit_;
}


Rank Card::get_rank() const noexcept
{
	return rank_;
}


Color Card::get_color() const noexcept
{
	return color_;
}