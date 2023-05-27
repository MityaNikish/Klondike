#pragma once
#include <exception>

class klondike_exception : public std::exception {};

class invalid_value_exception : public klondike_exception {
    const char* what() const noexcept override;
};

class card_exception : public klondike_exception {
    const char* what() const noexcept override;
};

class deck_exception : public klondike_exception {
    const char* what() const noexcept override;
};

class stack_cards_exception : public klondike_exception {
    const char* what() const noexcept override;
};

class game_exception : public klondike_exception {
    const char* what() const noexcept override;
};