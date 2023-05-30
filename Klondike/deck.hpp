#pragma once
#include <vector>
#include "card.hpp"

class Deck final
{
public:
	Deck();
	void shuffle_deck(const int seed);
	[[nodiscard]] Card get_active_card() const;
	void delete_card();
	void next();
	[[nodiscard]] size_t get_number_card() const noexcept;
	[[nodiscard]] bool empty() const noexcept;

	bool operator==(const Deck&) const = default;
private:
	std::vector<Card> deck_;
	size_t active_card_;
};