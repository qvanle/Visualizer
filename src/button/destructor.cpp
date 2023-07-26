#include <button.hpp>

Button::~Button() {
    render = nullptr;

    for(auto&i : sprites) {
        delete i;
    }
    sprites.clear();
}
