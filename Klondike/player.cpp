#include "player.hpp"


Player::Player(const std::string& name) : score_(0)
{
	name_ = name;
};


size_t Player::get_score() const noexcept
{
	return score_;
}


const std::string& Player::get_name() const noexcept
{
	return name_;
}


void Player::add_point(size_t point) noexcept
{
	score_ += point;
}


void Player::subtract_point(size_t point) noexcept
{
	score_ = score_ < point ? 0 : score_ - point;
}