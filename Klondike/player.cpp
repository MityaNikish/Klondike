#include "player.hpp"


Player::Player() : score_(0), name_("Player") {};

Player::Player(const std::string& name) : score_(0)
{
	name_ = name;
};


size_t Player::get_score() const
{
	return score_;
}


std::string Player::get_name() const
{
	return name_;
}


void Player::set_name(const std::string& name)
{
	name_ = name;
}


void Player::add_point(size_t point)
{
	score_ += point;
}


void Player::subtract_point(size_t point)
{
	score_ = score_ < point ? 0 : score_ - point;
}