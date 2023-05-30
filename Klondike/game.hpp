#pragma once
#include <vector>
#include "deck.hpp"
#include "stack_cards.hpp"
#include "row_cards.hpp"
#include "UI.hpp"
#include "player.hpp"
#include <memory>
#include "index.hpp"


class Game final
{
public:
	Game(const std::string& name_player);
	void start_game();
	[[nodiscard]] bool move_card_from_deck_to_stackcards(const IndexStack index_to);
	[[nodiscard]] bool move_card_from_deck_to_rowcards(const IndexRow index_to);
	[[nodiscard]] bool move_card_from_rowcards_to_stackcards(const IndexRow index_from_where, const IndexStack index_to);
	[[nodiscard]] bool move_card_from_rowcards_to_rowcards(const int count_cards, const IndexRow index_from, const IndexRow index_to);
	void skip_card_desk();
	void update_view() const;

private:
	static const size_t count_stacks;
	static const size_t count_rows;
	Deck deck_;
	std::vector<StackCards> stacks_cards_;
	std::vector<RowCards> rows_cards_;
	std::unique_ptr<UI> view_;
	Player player_;
};
