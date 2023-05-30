#pragma once

//enum class IndexType
//{
//	Row = 7,
//	Stack = 4
//};
//
//template<IndexType T>
//class Index final
//{
//public:
//	explicit Index(size_t index) : max_count(static_cast<size_t>(T)), index_(index) {}
//
//	[[nodiscard]] bool check_validity() const noexcept
//	{
//		return index_ < 0 || index_ > max_count;
//	}
//
//	[[nodiscard]] size_t get_index() const noexcept
//	{
//		return index_;
//	}
//private:
//	const size_t max_count;
//	size_t index_;
//};


class IndexRow final
{
public:
	IndexRow(size_t index): max_count(7), index_(index) {}

	[[nodiscard]] bool check_validity() const noexcept
	{
		return index_ < 0 || index_ > max_count;
	}

	[[nodiscard]] size_t get_index() const noexcept
	{
		return index_;
	}
private:
	const size_t max_count;
	size_t index_;
};


class IndexStack final
{
public:
	IndexStack(size_t index) : max_count(4), index_(index) {}

	[[nodiscard]] bool check_validity() const noexcept
	{
		return index_ < 0 || index_ > max_count;
	}

	[[nodiscard]] size_t get_index() const noexcept
	{
		return index_;
	}
private:
	const size_t max_count;
	size_t index_;
};