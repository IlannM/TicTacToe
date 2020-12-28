// TicTacToe 3.1 - main.cpp
// Ilan Mittelman - 9/6/2020
// under the MIT licence.

#include "functions.hpp"
#include <iostream>

int main()
{
    char grid[3][3]{}; // 3x3 grid

    create_grid(grid);

    // start game

    char player {starting_player()};
    int move = 0;
    bool player_won {false};
    bool already_taken {false};

    for (int plays = 0; plays < 9;) // the '++plays' is on line 40
    {
        if (!already_taken) {
            display_grid(grid);
        } else {
            already_taken = false;
        }

        move = player_move(player);

        // move-1 because we need to start counting with
        if (is_taken(move-1, grid))
        {
            std::cout << "Already taken.\n";
            already_taken = true;
            continue;
        }

        write_to_grid(grid, move, player);

        ++plays;

        // start checking if a player won
        if (plays > 4 && won(player, grid))
        {
            player_won = true;
            display_grid(grid);
            std::cout << player << " won.\n";
            break;
        }

        player = change_player(player);
    }

    if (!player_won)
        std::cout << "Draw.\n\n";

    if (get_export())
        export_game_f(grid, !player_won, player);

    std::cout << "\nThank you for playing!\n\n";

    finish_game();

	return 0;
}
