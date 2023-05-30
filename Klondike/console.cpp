#include "console.hpp"
#include <iostream>
#include <string>
#include "exception.hpp"


namespace 
{
	void draw_suit(Suit suit)
	{
		std::string suit_card;

		switch (suit)
		{
		case Suit::clubs:
			suit_card = "Clubs";
			break;
		case Suit::diamonds:
			suit_card = "Diamond";
			break;
		case Suit::hearts:
			suit_card = "Hearts";
			break;
		case Suit::spades:
			suit_card = "Spades";
			break;
		default:
			throw ui_exception();
		}
		std::cout << suit_card;
	}

	void draw_rank(Rank rank)
	{
		std::string rank_card;

		switch (rank)
		{
		case Rank::ace:
			rank_card = "Ace";
			break;
		case Rank::two:
			rank_card = "2";
			break;
		case Rank::three:
			rank_card = "3";
			break;
		case Rank::four:
			rank_card = "4";
			break;
		case Rank::five:
			rank_card = "5";
			break;
		case Rank::six:
			rank_card = "6";
			break;
		case Rank::seven:
			rank_card = "7";
			break;
		case Rank::eight:
			rank_card = "8";
			break;
		case Rank::nine:
			rank_card = "9";
			break;
		case Rank::ten:
			rank_card = "10";
			break;
		case Rank::jack:
			rank_card = "Jack";
			break;
		case Rank::queen:
			rank_card = "Queen";
			break;
		case Rank::king:
			rank_card = "King";
			break;
		default:
			throw ui_exception();
		}
		std::cout << rank_card;
	}

	void draw_color(Color color)
	{
		std::string color_card;

		switch (color)
		{
		case Black:
			color_card = "(Black)";
			break;
		case Red:
			color_card = "(Red)";
			break;
		default:
			throw ui_exception();
		}
		std::cout << color_card;
	}
}

void Console::clear()
{
	system("cls");
}

void Console::draw_info(const Player& player)
{
	std::cout << "*** " << player.get_name() << " has " << player.get_score() << " point ***" << std::endl << std::endl;
}


void Console::draw_deck(const Deck& deck)
{
	std::cout << "Deck" << std::endl;

	if (deck.get_number_card() == 0)
	{
		std::cout << "Empty deck" << std::endl;
		return;
	}

	draw_rank(deck.get_active_card().get_rank());
	std::cout << "  ";
	draw_suit(deck.get_active_card().get_suit());
	draw_color(deck.get_active_card().get_color());
	std::cout << std::endl << std::endl;
}


void Console::draw_stack_cards(const size_t number, const StackCards& stack_cards)
{
	std::cout << "[" << number << "]" "Stack cards - ";
	draw_suit(stack_cards.get_suit());
	std::cout << std::endl;

	for (auto card : stack_cards.get_date())
	{
		draw_rank(card.get_rank());
		std::cout << "  ";
		draw_suit(card.get_suit());
		draw_color(card.get_color());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void Console::draw_row_cards(const size_t number, const RowCards& row_cards)
{
	std::cout << "[" << number << "]" "Row cards " << std::endl;

	for (auto card : row_cards.get_date())
	{
		draw_rank(card.get_rank());
		std::cout << "  ";
		draw_suit(card.get_suit());
		draw_color(card.get_color());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
