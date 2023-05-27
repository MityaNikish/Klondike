#pragma once
#include <unordered_map>

enum Suit
{
	spades,     //����  - ������
	clubs,     //����� - ������
	diamonds,  //����� - �������
	hearts    //����� - �������
};

enum Rank
{
	ace,
	two, three, four, five, six, seven, eight, nine, ten,
	jack,
	queen,
	king
};

enum Color
{
	Black,
	Red
};

class Card final
{
public:
	Card() = delete;
	Card(const Suit suit, const Rank rank);
	[[nodiscard]] Suit get_suit() const noexcept;
	[[nodiscard]] Rank get_rank() const noexcept;
	[[nodiscard]] Color get_color() const noexcept;

	bool operator==(const Card&) const = default;
private:
	Suit suit_;
	Rank rank_;
	Color color_;
	static std::unordered_map<Suit, Color> color_suit;
};