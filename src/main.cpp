// TicTacToe 3.1 - main.cpp
// Ilan Mittelman - 9/6/2020
// under the MIT licence.

#include "functions.hpp"
#include <cstdio>

int main()
{
    char grid[3][3] { // 3x3 grid
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };

    // create_grid(grid);

    // start game
    char player {starting_player()};
    int move = 0;
    bool player_won {false};
    bool already_taken {false};

    for (int plays = 0; plays < 9;) // the '++plays' is on line 40
    {
        if (!already_taken)
            display_grid(grid);
        else
            already_taken = false;

        move = player_move(player);

        // move-1 because we need to start counting with
        already_taken = is_taken(move-1, grid);
        if (already_taken)
        {
            puts("Already taken.");
            continue;
        }

        write_to_grid(grid, move, player);

        ++plays;

        // start checking if a player won
        if (plays > 4 && won(player, grid))
        {
            player_won = true;
            display_grid(grid);
            printf("\'%c\' won.\n", player);
            break;
        }

        player = change_player(player);
    }

    if (!player_won)
        puts("Draw.\n");

    if (get_export())
        export_game_f(grid, !player_won, player);

    puts("\nThank you for playing!\n");

    finish_game();

	return 0;
}
