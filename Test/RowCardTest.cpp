#include "pch.h"
#include "row_cards.hpp"
#include "exception.hpp"

TEST(row_cards__constructor, test) {
	const RowCards row;
	EXPECT_TRUE(row.empty());
}

TEST(row_cards__try_push_card, is_not_empty) {
	RowCards row;
	const Card card(Suit::clubs, Rank::king);

	EXPECT_TRUE(row.try_push_card(card));
	EXPECT_TRUE(!row.empty());
}

TEST(row_cards__get_back, test) {
	RowCards row;
	const Card card(Suit::clubs, Rank::king);

	EXPECT_TRUE(row.try_push_card(card));
	EXPECT_EQ( row.get_back(), card);
}

TEST(row_cards__size, after_push) {
	RowCards row;
	const Card card(Suit::clubs, Rank::king);

	EXPECT_TRUE(row.try_push_card(card));
	EXPECT_EQ(row.size(), 1);
}

TEST(row_cards__size, after_pop) {
	RowCards row;
	const Card card(Suit::clubs, Rank::king);

	EXPECT_TRUE(row.try_push_card(card));
	row.pop_back();

	EXPECT_EQ(row.size(), 0);
}

TEST(row_cards__try_move_card_in_row, test) {
	RowCards row1, row2;

	const Card card(Suit::clubs, Rank::king);

	EXPECT_TRUE(row1.try_push_card(card));
	EXPECT_TRUE(!row1.empty());
	EXPECT_TRUE(row2.empty());

	EXPECT_TRUE(row1.try_move_card_in_row(row2));

	EXPECT_TRUE(row1.empty());
	EXPECT_TRUE(!row2.empty());
}


TEST(row_cards__add_card, test) {
	RowCards row;

	const Card card(Suit::clubs, Rank::king);
	for (size_t counter = 0; counter < 10; counter++)
	{
		row.add_card(card);
	}
	EXPECT_EQ(row.size(), 10);
}

TEST(row_cards__get_date, test) {
	RowCards row;

	const Card card(Suit::clubs, Rank::king);

	for (size_t counter = 0; counter < 10; counter++)
	{
		row.add_card(card);
	}
	EXPECT_EQ(row.size(), 10);

	std::vector<Card> cards = row.get_date();
	EXPECT_EQ(cards.size(), 10);
}

TEST(row_cards__EXCEPTION, of_pop_back) {
	RowCards row;

	EXPECT_THROW({ row.pop_back(); }, row_cards_exception);
}

TEST(row_cards__EXCEPTION, of_get_back) {
	RowCards row;

	EXPECT_THROW({ Card card = row.get_back(); }, row_cards_exception);
}