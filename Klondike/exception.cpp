#include "exception.hpp"


const char* invalid_value_exception::what() const noexcept {
    return "Invalid value";
}


const char* deck_exception::what() const noexcept {
    return "Deck is empty";
}

const char* stack_cards_exception::what() const noexcept {
    return "Stack cards is empty";
}

const char* game_exception::what() const noexcept {
    return "Design error";
}