#include "pch.h"
#include <fstream>
#include "game.hpp"

//--------------------------------------------------------------------------------------------------------------//

TEST(card__constructor, test) {
	const Card card(Suit::clubs, Rank::ace);

	EXPECT_EQ(card.get_rank(), Rank::ace);
	EXPECT_EQ(card.get_suit(), Suit::clubs);
	EXPECT_EQ(card.get_color(), Color::Black);
}

//--------------------------------------------------------------------------------------------------------------//

TEST(deck__constructor, test__output_file) {
	Deck object;
	object.shuffle_deck();
	
	std::ofstream fin;
	fin.open("file.txt");


	for (int i = 0; i < 52; i++)
	{
		Card card = object.get_active_card();
		fin << card.get_suit() << "  " << card.get_rank() << std::endl;
		object.next();
	}
}

TEST(deck__shuffle_deck, test) {
	const Deck object1;
	Deck object2 = object1;
	object2.shuffle_deck();

	EXPECT_TRUE(!(object1 == object2));
}

TEST(deck__pick_up_the_card, test) {
	const Deck object;

	EXPECT_TRUE(object.get_active_card().get_rank() == Rank::ace);
}

TEST(deck__next, test_1) {
	Deck object;

	EXPECT_TRUE(object.next().get_rank() == Rank::two);
}

TEST(deck__next, test_2) {
	Deck object;

	object.next();
	EXPECT_TRUE(object.get_active_card().get_rank() == Rank::two);
}

//--------------------------------------------------------------------------------------------------------------//

TEST(stack_card__push_card, test__complete_first_card) {
	StackCards object(Suit::clubs);
	const Card card(Suit::clubs, Rank::ace);

	EXPECT_TRUE(object.push_card(card));
}

TEST(stack_card__push_card, test__uncomplete_first_card) {
	StackCards object(Suit::clubs);
	const Card card(Suit::clubs, Rank::two);

	EXPECT_TRUE(!object.push_card(card));
}

TEST(stack_card__push_card, test__uncomplete_suit) {
	StackCards object(Suit::clubs);
	const Card card(Suit::diamonds, Rank::ace);

	EXPECT_TRUE(!object.push_card(card));
}

TEST(stack_card__push_card, test__complete) {
	StackCards object(Suit::clubs);
	const std::vector<Rank> ranks = { Rank::ace, Rank::two, Rank::three };

	for (const auto rank : ranks)
	{
		const Card card(Suit::clubs, rank);
		EXPECT_TRUE(object.push_card(card));
	}
}

TEST(stack_card__push_card, test__uncomplete_rank) {
	StackCards object(Suit::clubs);
	const std::vector<Rank> ranks = { Rank::ace, Rank::two, Rank::three };

	size_t count = 0;
	bool complete = false;

	for (const auto rank : ranks)
	{
		const Card card(Suit::clubs, rank);
		bool complete = object.push_card(card);
		if (complete)
		{
			count++;
		}
		complete = false;
	}

	EXPECT_TRUE(count == 3);

	const Card card(Suit::clubs, Rank::queen);
	EXPECT_TRUE(!object.push_card(card));
}

TEST(stack_card__get_top, test_empty) {
	StackCards object(Suit::clubs);

	EXPECT_TRUE(object.empty());
}

TEST(stack_card__get_top, test) {
	StackCards object(Suit::clubs);
	const std::vector<Rank> ranks = { Rank::ace, Rank::two, Rank::three };

	size_t count = 0;

	for (const auto rank : ranks)
	{
		const Card card(Suit::clubs, rank);
		if (object.push_card(card))
		{
			count++;
		}
	}

	EXPECT_TRUE(count == 3);

	EXPECT_TRUE(!object.empty());

	if (object.empty() == false)
	{
		EXPECT_TRUE(object.get_top().get_rank() == Rank::three);
	}
}

//--------------------------------------------------------------------------------------------------------------//



TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}