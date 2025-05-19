#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "widget.hpp"
#include "game_master.hpp"
#include "button.hpp"

class TicTacToe : public Widget {
private:
    int grid_size;
    GameMaster master;
    Button reset_button;

public:
    TicTacToe(int x, int y, int size, int grid)
        : Widget(x, y, size, size),
          grid_size(grid),
          master(grid),
          reset_button(x + size - 100, y + 510, 90, 30, "Uj jatek")
    {}

    void draw() const override;
    void handle(genv::event ev) override;
    int get_cell_size() const { return _size_x / grid_size; }
};

#endif
