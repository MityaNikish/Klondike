#include "card.hpp"
#include <vector>
#include "exception.hpp"

namespace
{
	const std::unordered_map<Suit, Color> color_suit = { {spades, Black}, {clubs, Black}, {diamonds, Red}, {hearts, Red} };
	const std::vector<Rank> ranks = { ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen,	king };
}


Card::Card(const Suit suit, const Rank rank)
{
	auto iter = color_suit.find(suit);
	if (iter == color_suit.end())
	{
		throw card_exception();
	}
	if (std::ranges::find(ranks, rank) == ranks.end())
	{
		throw card_exception();
	}
	suit_ = suit;
	rank_ = rank;
	color_ = iter->second;
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