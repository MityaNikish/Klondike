#pragma once
#include <string>

class Player final
{
public:
	Player();
	[[nodiscard]] size_t get_score() const;
	[[nodiscard]] std::string get_name() const;
	void set_name(const std::string& name);
	void add_point(size_t point);
	void subtract_point(size_t point);
private:
	size_t score_;
	std::string name_;
};