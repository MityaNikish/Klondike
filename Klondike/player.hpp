#pragma once
#include <string>

class Player final
{
public:
	Player(const std::string& name);
	[[nodiscard]] size_t get_score() const noexcept;
	[[nodiscard]] const std::string& get_name() const noexcept;
	void add_point(size_t point) noexcept;
	void subtract_point(size_t point) noexcept;
private:
	size_t score_;
	std::string name_;
};