#pragma once
#include <vector>
#include "deck.hpp"
#include "stack_cards.hpp"
#include "row_cards.hpp"
#include "UI.hpp"
#include "player.hpp"
#include <memory>


class Game final
{
public:
	Game(const std::string& name_player);
	void start_game();
	[[nodiscard]] bool move_card_from_deck_to_stackcards(const size_t number_to_where);
	[[nodiscard]] bool move_card_from_deck_to_rowcards(const size_t number_to_where);
	[[nodiscard]] bool move_card_from_rowcards_to_stackcards(const size_t number_from_where, const size_t number_to_where);
	[[nodiscard]] bool move_card_from_rowcards_to_rowcards(const size_t from_wich_card, const size_t number_from_where, const size_t number_to_where);
	void skip_card_desk();

	void update_view() const;

private:
	Deck deck_;
	std::vector<StackCards> stacks_cards_;
	std::vector<RowCards> rows_cards_;
	std::unique_ptr<UI> view_;
	Player player_;
	static const size_t count_stacks;
	static const size_t count_rows;
};
