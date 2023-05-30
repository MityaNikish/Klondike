#include "exception.hpp"


const char* invalid_value_exception::what() const noexcept {
    return "Invalid value";
}

const char* ui_exception::what() const noexcept {
    return "Invalid value";
}

const char* index_exception::what() const noexcept {
    return "Invalid value";
}

const char* card_exception::what() const noexcept {
    return "Invalid card options";
}

const char* deck_exception::what() const noexcept {
    return "Deck is empty";
}

const char* stack_cards_exception::what() const noexcept {
    return "Stack cards is empty";
}

const char* row_cards_exception::what() const noexcept {
    return "Row cards is empty";
}

const char* game_exception::what() const noexcept {
    return "Design error";
}