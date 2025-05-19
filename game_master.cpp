#include "game_master.hpp"
#include <vector>

GameMaster::GameMaster(int size) : board(size, std::vector<int>(size, 0)), current_player(1) {}

bool GameMaster::place_marker(int row, int col) {
    if (row >= 0 && row < board.size() && col >= 0 && col < board.size()) {
        if (board[row][col] == 0) {
            board[row][col] = current_player;
            current_player = (current_player == 1) ? 2 : 1;
            return true;
        }
    }
    return false;
}

const std::vector<std::vector<int>>& GameMaster::get_board() const {
    return board;
}

int GameMaster::check_winner() const {
    int n = board.size();
    const int WIN_CONDITION = 5;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n - WIN_CONDITION; ++j) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3] &&
                board[i][j] == board[i][j + 4]) {
                return board[i][j];
            }
            if (board[j][i] != 0 &&
                board[j][i] == board[j + 1][i] &&
                board[j][i] == board[j + 2][i] &&
                board[j][i] == board[j + 3][i] &&
                board[j][i] == board[j + 4][i]) {
                return board[j][i];
            }
        }
    }

    for (int i = 0; i <= n - WIN_CONDITION; ++i) {
        for (int j = 0; j <= n - WIN_CONDITION; ++j) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3] &&
                board[i][j] == board[i + 4][j + 4]) {
                return board[i][j];
            }
        }
    }

    for (int i = 0; i <= n - WIN_CONDITION; ++i) {
        for (int j = WIN_CONDITION - 1; j < n; ++j) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i + 1][j - 1] &&
                board[i][j] == board[i + 2][j - 2] &&
                board[i][j] == board[i + 3][j - 3] &&
                board[i][j] == board[i + 4][j - 4]) {
                return board[i][j];
            }
        }
    }

    return 0;
}

bool GameMaster::is_full() const {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 0) {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::pair<int, int>> GameMaster::get_winning_coords() const {
    return winning_coords;
}

void GameMaster::reset() {
    for (auto& row : board) {
        for (auto& cell : row) {
            cell = 0;
        }
    }
    current_player = 1;
    winning_coords.clear();
}
