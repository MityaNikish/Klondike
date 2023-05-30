#include <iostream>
//#include "deck.hpp"
//#include  "stack_cards.hpp"
//#include  "row_cards.hpp"
#include "game.hpp"
#include "index.hpp"
#include "exception.hpp"

enum KeyPad
{
	exit_ = -1,
	next = 1,
	from_deck_to_row = 2,
	from_deck_to_stack = 3,
	from_row_to_row = 4,
	from_row_to_stack = 5
};

int inspector(std::string str)
{
	const char* pattern = "0123456789-";
	std::string arg;
	std::cout << str;
	std::cin >> arg;

	if (arg.find_first_not_of(pattern) == std::string::npos)
	{
		return std::stoi(arg);
	}
	return 0;
}


const std::vector<int>& foo(std::vector<int>& arr)
{
	arr.push_back(1);
	return arr;
}


int main()
{
	std::string name;
	std::cout << "Input name player: ";
	getline(std::cin, name);

	Game game(name);
	game.start_game();

	game.update_view();
	int key = 0;
	bool right = true;

	while (key != exit_)
	{
		if (!right)
		{
			std::cout << "The previous action failed!\nThink better!\n" << std::endl;
			right = true;
		}
		else
		{
			std::cout << "\n\n\n";
		}

		int number_from, number_to, count;
		key = inspector("First wave event.\n[Show the next card in the deck - 1;\tPut a card from deck to row - 2;\tPut a card from deck to stack - 3;\n"
			"Move a card from row to row - 4;\tMove a card from row to stack = 5]\nSelect an action: ");
		//std::cout << ;
		//std::cin >> key;

		std::cout << "\nSecond  wave event.\n";
		switch (key)
		{
		case next:
			game.skip_card_desk();
			break;
		case from_row_to_row:
			number_from = inspector("Choose where from: ");
			number_to = inspector("Choose where: ");
			count = inspector("Count cards: ");
			right = game.move_card_from_rowcards_to_rowcards(count, IndexRow(number_from), IndexRow(number_to));
			break;
		case from_row_to_stack:
			number_from = inspector("Choose where from: ");
			number_to = inspector("Choose where: ");
			right = game.move_card_from_rowcards_to_stackcards(IndexRow(number_from), IndexStack(number_to));
			break;
		case from_deck_to_row:
			number_to = inspector("Choose where: ");
			right = game.move_card_from_deck_to_rowcards(IndexRow(number_to));
			break;
		case from_deck_to_stack:
			number_to = inspector("Choose where: ");
			right = game.move_card_from_deck_to_stackcards(IndexStack(number_to));
			break;
		default:
			right = false;
			break;
		}

		game.update_view();
	}

	return 0;
}
