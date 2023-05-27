#pragma once
#include "UI.hpp"

class Console final : public UI
{
public:
	void clear() override;
	void draw_info(const Player& player) override;
	void draw_deck(const Deck& deck) override;
	void draw_stack_cards(const size_t number, const StackCards& stack_cards) override;
	void draw_row_cards(const size_t number, const RowCards& row_cards) override;
};