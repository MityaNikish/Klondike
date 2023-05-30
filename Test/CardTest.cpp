#include "pch.h"
#include "card.hpp"
#include "exception.hpp"


namespace
{
	const std::vector<Suit> suits = { spades, clubs, diamonds, hearts };
	const std::vector <Rank> ranks = { ace, two, three, four, five, six, seven, eight, nine, ten,	jack, queen, king };
}


TEST(card__constructor, test) {
	const Card card(Suit::clubs, Rank::ace);

	EXPECT_EQ(card.get_rank(), Rank::ace);
	EXPECT_EQ(card.get_suit(), Suit::clubs);
	EXPECT_EQ(card.get_color(), Color::Black);
}

TEST(card__get_suit, chek_all_suits) {
	for (auto suit: suits)
	{
		const Card card(suit, Rank::ace);
		EXPECT_EQ(card.get_suit(), suit);
	}
}

TEST(card__get_color, chek_all_suits) {
	for (size_t i = 0; i < 2; i++)
	{
		const Card card(suits[i], Rank::ace);
		EXPECT_EQ(card.get_color(), Color::Black);
	}
	for (size_t i = 2; i < 4; i++)
	{
		const Card card(suits[i], Rank::ace);
		EXPECT_EQ(card.get_color(), Color::Red);
	}
}

TEST(card__get_rank, chek_all_ranks) {
	for (auto rank : ranks)
	{
		const Card card(Suit::spades, rank);
		EXPECT_EQ(card.get_rank(), rank);
	}
}

TEST(card__operator_equal, test) {
	const Card card1(Suit::spades, Rank::ace);
	const Card card2(card1);

	EXPECT_TRUE(card1 == card2);
}

TEST(card__EXCEPTION, test) {
	EXPECT_THROW({ Card card(static_cast<Suit>(-1), Rank::ace); }, card_exception);
}