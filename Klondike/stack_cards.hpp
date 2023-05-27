#pragma once
#include <vector>
#include "card.hpp"

class StackCards final
{
public:
	StackCards() = delete;
	StackCards(Suit suit_stack);
	[[nodiscard]] bool try_push_card(const Card& card);
	[[nodiscard]] Card get_top() const;
	[[nodiscard]] bool empty() const noexcept;
	[[nodiscard]] const std::vector<Card>& get_date() const noexcept;
	[[nodiscard]] Suit get_suit() const noexcept;

private:
	std::vector<Card> stack_;
	Suit suit_stack_;
};
