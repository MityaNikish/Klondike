#pragma once
#include <vector>
#include "card.hpp"

class RowCards final
{
public:
	RowCards();
	[[nodiscard]] bool try_push_card(const Card& card);
	void add_card(const Card& card);
	[[nodiscard]] bool try_move_card_in_row(RowCards& new_row_card);
	[[nodiscard]] const std::vector<Card>& get_date() const noexcept;
	void pop_back();
	[[nodiscard]] Card get_back() const;
	[[nodiscard]] bool empty() const noexcept;
	[[nodiscard]] size_t size() const noexcept;
private:
	static bool hitch_check(const Card& prev_card, const Card& card);
private:
	std::vector<Card> row_;
};