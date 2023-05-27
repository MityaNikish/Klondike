#pragma once
#include "deck.hpp"
#include "stack_cards.hpp"
#include "row_cards.hpp"
#include "player.hpp"

class UI
{
public:
	virtual ~UI() = default;
	virtual void clear() = 0;
	virtual void draw_info(const Player& player) = 0;
	virtual void draw_deck(const Deck& deck) = 0;
	virtual void draw_stack_cards(const size_t number, const StackCards& stack_cards) = 0;
	virtual void draw_row_cards(const size_t number, const RowCards& row_cards) = 0;
};