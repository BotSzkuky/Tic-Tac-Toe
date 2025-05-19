#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widget.hpp"
#include "graphics.hpp"
#include <string>

class Button : public Widget {
private:
    std::string label;
    bool pressed;

public:
    Button(int x, int y, int sx, int sy, const std::string& text)
        : Widget(x, y, sx, sy), label(text), pressed(false) {}

    void draw() const override {
        using namespace genv;
        gout << color(150, 150, 150) << move_to(_x, _y) << box(_size_x, _size_y);
        gout << color(0, 0, 0);
        int tw = gout.twidth(label);
        int th = gout.cascent() + gout.cdescent();
        gout << move_to(_x + (_size_x - tw) / 2, _y + (_size_y + th) / 2 - 25) << text(label);
    }

    void handle(genv::event ev) override {
        if (ev.type == genv::ev_mouse && ev.button == genv::btn_left) {
            if (is_selected(ev.pos_x, ev.pos_y)) {
                pressed = true;
            } else {
                pressed = false;
            }
        }
    }

    bool is_pressed() {
        if (pressed) {
            pressed = false;
            return true;
        }
        return false;
    }
};

#endif
