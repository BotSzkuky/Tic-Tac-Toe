#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include <vector>
#include <utility>

class GameMaster {
private:
    int grid_size;
    std::vector<std::vector<int>> board;
    int current_player;
    std::vector<std::pair<int, int>> winning_coords;

public:
    GameMaster(int size);

    bool place_marker(int row, int col);
    int check_winner() const;
    bool is_full() const;
    const std::vector<std::vector<int>>& get_board() const;
    std::vector<std::pair<int, int>> get_winning_coords() const;

    void reset();
};

#endif
