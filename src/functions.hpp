// TicTacToe 3.1 - functions.hpp
// Ilan Mittelman - 9/6/2020
// under the MIT licence.

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

int player_move(const char &player);
char starting_player();
void create_grid(char grid[3][3]);
void display_grid(const char grid[3][3]);
char change_player(const char &current_player);
void write_to_grid(char grid[3][3], const int &player_move, const char &player);
bool is_taken(const int player_move, const char grid[3][3]);
bool won(const char player, const char grid[3][3]);
bool get_export();
void export_game_f(const char grid[3][3], const bool &draw, const char &player);
void finish_game();

#endif