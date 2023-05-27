#include "card.hpp"
#include <vector>
#include "exception.hpp"


std::unordered_map<Suit, Color> Card::color_suit = { {spades, Black}, {clubs, Black}, {diamonds, Red}, {hearts, Red} };

Card::Card(const Suit suit, const Rank rank)
{
	if (static_cast<int>(spades) > static_cast<int>(suit) && static_cast<int>(hearts) < static_cast<int>(suit))
	{
		throw card_exception();
	}
	if (static_cast<int>(ace) > static_cast<int>(rank) && static_cast<int>(king) < static_cast<int>(rank))
	{
		throw card_exception();
	}
	suit_ = suit;
	rank_ = rank;
	color_ = color_suit.find(suit)->second;
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