#include "graphics.hpp"
#include "tic_tac_toe.hpp"

using namespace genv;

int main() {
    gout.open(600, 600);
    gout << font("LiberationSans-Regular.ttf", 20);

    TicTacToe game(50, 50, 500, 15);

    event ev;
    while (gin >> ev && ev.keycode != key_escape) {
        game.handle(ev);
        gout << move_to(0,0) << color(255,255,255) << box(600,600);
        game.draw();
        gout << refresh;
    }
    return 0;
}
