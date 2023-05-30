#include "pch.h"
#include "deck.hpp"
#include "exception.hpp"

TEST(deck__constructor, test) {
	const Deck deck;
	EXPECT_EQ(deck.get_number_card(), 52);
}

TEST(deck__shuffle_deck, seed_0) {
	const Deck deck;
	Deck deck_shuffle(deck);

	deck_shuffle.shuffle_deck(0);

	EXPECT_EQ(deck_shuffle.get_number_card(), 52);
	EXPECT_TRUE(deck != deck_shuffle);
}

TEST(deck__get_active_card, test) {
	const Deck deck;
	
	const Card card = deck.get_active_card();

	EXPECT_EQ(card.get_rank(), Rank::ace);
	EXPECT_EQ(card.get_suit(), Suit::clubs);
	EXPECT_EQ(card.get_color(), Color::Black);
}

TEST(deck__next, test) {
	Deck deck;

	Card card = deck.get_active_card();

	EXPECT_EQ(card.get_rank(), Rank::ace);
	EXPECT_EQ(card.get_suit(), Suit::clubs);
	EXPECT_EQ(card.get_color(), Color::Black);

	deck.next();
	card = deck.get_active_card();

	EXPECT_EQ(card.get_rank(), Rank::two);
	EXPECT_EQ(card.get_suit(), Suit::clubs);
	EXPECT_EQ(card.get_color(), Color::Black);
}

TEST(deck__delete_card, test) {
	Deck deck;

	Card card = deck.get_active_card();

	EXPECT_EQ(card.get_rank(), Rank::ace);
	EXPECT_EQ(card.get_suit(), Suit::clubs);
	EXPECT_EQ(card.get_color(), Color::Black);

	deck.delete_card();
	card = deck.get_active_card();

	EXPECT_EQ(card.get_rank(), Rank::two);
	EXPECT_EQ(card.get_suit(), Suit::clubs);
	EXPECT_EQ(card.get_color(), Color::Black);
}

TEST(deck__empty, test) {
	Deck deck;

	for (size_t counter = 0; counter < 52; counter++)
	{
		deck.delete_card();
	}

	EXPECT_TRUE(deck.empty());
}

TEST(deck__equals, test) {
	const Deck deck;
	Deck deck_changer(deck);

	EXPECT_TRUE(deck == deck_changer);
	deck_changer.delete_card();
	EXPECT_TRUE(deck != deck_changer);
}

TEST(deck__EXCEPTION, of_get_active_card) {
	Deck deck;

	for (size_t counter = 0; counter < 52; counter++)
	{
		deck.delete_card();
	}

	EXPECT_THROW({ Card card = deck.get_active_card(); }, deck_exception);
}

TEST(deck__EXCEPTION, of_delete_card) {
	Deck deck;

	for (size_t counter = 0; counter < 52; counter++)
	{
		deck.delete_card();
	}

	EXPECT_THROW({ deck.delete_card(); }, deck_exception);
}

TEST(deck__EXCEPTION, of_next) {
	Deck deck;

	for (size_t counter = 0; counter < 52; counter++)
	{
		deck.delete_card();
	}

	EXPECT_THROW({ deck.next(); }, deck_exception);
}