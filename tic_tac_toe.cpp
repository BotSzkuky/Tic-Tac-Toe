#include "tic_tac_toe.hpp"
#include "graphics.hpp"

using namespace genv;

void TicTacToe::draw() const {
    int cell_size = get_cell_size();

    for (int i = 0; i <= grid_size; ++i) {
        gout << color(200, 200, 200);
        gout << move_to(_x + i * cell_size, _y) << line(0, _size_y);
        gout << move_to(_x, _y + i * cell_size) << line(_size_x, 0);
    }

    const auto& board = master.get_board();
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            int value = board[i][j];
            int center_x = _x + j * cell_size + cell_size / 2;
            int center_y = _y + i * cell_size + cell_size / 50;

            if (value == 1) {
                gout << color(255, 0, 0);
                int tw = gout.twidth("X");
                int th = gout.cascent() + gout.cdescent();
                gout << move_to(center_x - tw / 2, center_y + th / 2) << text("X");
            }
            else if (value == 2) {
                gout << color(0, 0, 255);
                int tw = gout.twidth("O");
                int th = gout.cascent() + gout.cdescent();
                gout << move_to(center_x - tw / 2, center_y + th / 2) << text("O");
            }
        }
    }

    reset_button.draw();

    int winner = master.check_winner();
    if (winner == 1) {
        gout << color(255, 0, 0) << move_to(50, 20) << text("Elso jatekos nyert!");
    }
    else if (winner == 2) {
        gout << color(0, 0, 255) << move_to(50, 20) << text("Masodik jatekos nyert!");
    }
    else if (master.is_full()) {
        gout << color(255, 255, 0) << move_to(50, 20) << text("Dontetlen! Elfogytak a lepesek!");
    }
}

void TicTacToe::handle(genv::event ev) {
    reset_button.handle(ev);
    if (reset_button.is_pressed()) {
        master.reset();
        return;
    }

    if (master.check_winner() != 0 || master.is_full()) {
        return;
    }

    if (ev.button == genv::btn_left) {
        int cell_size = get_cell_size();
        int row = (ev.pos_y - _y) / cell_size;
        int col = (ev.pos_x - _x) / cell_size;

        master.place_marker(row, col);
    }
}

