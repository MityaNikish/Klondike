#include "pch.h"
#include "stack_cards.hpp"
#include "exception.hpp"

TEST(stack_cards__constructor, suit_is_clubs) {
	const StackCards stack(Suit::clubs);
	EXPECT_EQ(stack.get_suit(), Suit::clubs);
}

TEST(stack_cards__empty, is_empty) {
	const StackCards stack(Suit::clubs);
	EXPECT_TRUE(stack.empty());
}

TEST(stack_cards__try_push_card, test) {
	StackCards stack(Suit::clubs);
	const Card card(Suit::clubs, Rank::ace);

	EXPECT_TRUE(stack.try_push_card(card));
	EXPECT_TRUE(!stack.empty());
}

TEST(stack_cards__get_suit, test) {
	StackCards stack(Suit::clubs);
	const Card card(stack.get_suit(), Rank::ace);

	EXPECT_TRUE(stack.try_push_card(card));
	EXPECT_TRUE(!stack.empty());
}

TEST(stack_cards__get_top, test) {
	StackCards stack(Suit::clubs);
	const Card card(stack.get_suit(), Rank::ace);

	EXPECT_TRUE(stack.try_push_card(card));
	if (!stack.empty()) {
		EXPECT_EQ(card, stack.get_top());
	}
}

TEST(stack_cards__EXCEPTION, of_get_top) {
	StackCards stack(Suit::clubs);

	EXPECT_THROW({ Card card = stack.get_top(); }, stack_cards_exception);
}

TEST(stack_cards__get_date, stack_is_empty) {
	const StackCards stack(Suit::clubs);
	std::vector<Card> cards = stack.get_date();

	EXPECT_TRUE(cards.empty());
}

TEST(stack_cards__get_date, stack_is_not_empty) {
	StackCards stack(Suit::clubs);
	const Card card(stack.get_suit(), Rank::ace);

	EXPECT_TRUE(stack.try_push_card(card));

	std::vector<Card> cards = stack.get_date();

	EXPECT_TRUE(!cards.empty());
}

TEST(stack_cards__get_date, test) {
	StackCards stack(Suit::clubs);
	const Card card(stack.get_suit(), Rank::ace);

	EXPECT_TRUE(stack.try_push_card(card));

	std::vector<Card> cards = stack.get_date();
	EXPECT_TRUE(!cards.empty());
}