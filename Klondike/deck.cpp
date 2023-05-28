#include "deck.hpp"
#include <random>
#include "exception.hpp"


const std::vector<Suit> Deck::suits = { clubs, diamonds, hearts, spades };

const std::vector<Rank> Deck::ranks = { ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen,	king };

Deck::Deck()
{	
	for (const auto suit : suits)
	{
		for (const auto rank : ranks)
		{
			Card card(suit, rank);
			deck_.push_back(card);
		}
	}
	active_card_ = 0;
}


void Deck::shuffle_deck(const int seed)
{
	std::mt19937 rng(seed);
	std::ranges::shuffle(deck_, rng);
}


Card Deck::get_active_card() const
{
	if (deck_.empty())
	{
		throw deck_exception();
	}

	return deck_[active_card_];
}


void Deck::delete_card()
{
	if (deck_.empty())
	{
		throw deck_exception();
	}

	deck_.erase(deck_.begin() + static_cast<int>(active_card_));
	active_card_ = active_card_ >= deck_.size() ? 0 : active_card_;
}


void Deck::next()
{
	if (deck_.empty())
	{
		throw deck_exception();
	}

	active_card_ = active_card_ + 1 >= deck_.size() ? 0 : active_card_ + 1;
}

size_t Deck::get_number_card() const noexcept
{
	return deck_.size();
}

bool Deck::empty() const noexcept
{
	return deck_.empty();
}