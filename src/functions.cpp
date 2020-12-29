// TicTacToe 3.1 - functions.cpp
// Ilan Mittelman - 9/6/2020
// under the MIT licence.

#include "time.hpp"
#include "random.hpp"
#include <iostream>
#include <fstream>

static void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(32767,'\n');
}

static char get_random_player()
{
    return (get_random_num(0, 1)) ? 'X' : 'O';
}

int player_move(const char &player)
{
    int move = 0;
    std::cout << player << ": ";
    bool failed {false};

    do {
        if (failed)
            std::cout << "The number must be betweem 1-9.\n";
        
        std::cin >> move;

        // handle invalid input
        if (std::cin.fail())
            clear_cin();
        
        failed = true;
    } while (move < 1 || move > 9);

    return move;
}

char starting_player()
{
    char player = 0;
    bool firsrt_time {true};
    std::cout << "Starting player (X/O).\n";
    std::cout << "Enter \'r\' to be random.\n";

    while (player != 'X' && player != 'O' && player != 'R')
    {
        if (!firsrt_time)
        {
            std::cout << "(The option must be \'X\' or \'O\')\n";
            std::cin.ignore(32767,'\n');
        }

        else if (firsrt_time)
            firsrt_time = false;

        std::cin >> player;

        player = toupper(player);
    }

    if (player == 'R') // random player
        return get_random_player();

    return player; // 'X' or 'O'
}

void create_grid(char grid[3][3])
{
    // write to the grid numbers from 1 to 9
    char grid_index = '1';

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j, ++grid_index)
        {
            grid[i][j] = grid_index;
        }
    }
}

void display_grid(const char grid[3][3])
{
    std::cout << '\n';
    for (int i = 0; i < 3; ++i)
    {
        std::cout << ' ';
        for (int j = 0; j < 3; ++j)
        {
            std::cout << grid[i][j];

            if (j == 2)
                continue;

            std::cout << " | ";
        }
        if (i == 2)
            continue;

        std::cout << "\n---|---|---\n";
    }
    std::cout << "\n\n";
}

char change_player(const char &current_player)
{
    return (current_player == 'X') ? 'O' : 'X';
}

void write_to_grid(char grid[3][3], const int &player_move, const char &player)
{
    switch (player_move)
    {
    case 1:
        grid[0][0] = player;
        break;
    case 2:
        grid[0][1] = player;
        break;
    case 3:
        grid[0][2] = player;
        break;
    case 4:
        grid[1][0] = player;
        break;
    case 5:
        grid[1][1] = player;
        break;
    case 6:
        grid[1][2] = player;
        break;
    case 7:
        grid[2][0] = player;
        break;
    case 8:
        grid[2][1] = player;
        break;
    case 9:
        grid[2][2] = player;
        break;
    default:
        std::cout << "An unexpected error ocurred.\n";
        break;
    }
}

bool is_taken(const int player_move, const char grid[3][3])
{
    switch (player_move)
    {
    case 0:
        return ((grid[0][0] == 'O') || (grid[0][0] == 'X'));
    case 1:
        return ((grid[0][1] == 'O') || (grid[0][1] == 'X'));        
    case 2:
        return ((grid[0][2] == 'O') || (grid[0][2] == 'X'));        
    case 3:
        return ((grid[1][0] == 'O') || (grid[1][0] == 'X'));
    case 4:
        return ((grid[1][1] == 'O') || (grid[1][1] == 'X'));
    case 5:
        return ((grid[1][2] == 'O') || (grid[1][2] == 'X'));
    case 6:
        return ((grid[2][0] == 'O') || (grid[2][0] == 'X'));
    case 7:
        return ((grid[2][1] == 'O') || (grid[2][1] == 'X'));
    case 8:
        return ((grid[2][2] == 'O') || (grid[2][2] == 'X'));
    default:
        return false;
    }
    return false;
}

bool won(const char player, const char grid[3][3])
{
    if ((grid[0][0] == player) && (grid[0][1] == player) && (grid[0][2] == player)) { // upper row
        return true;
    }
    else if ((grid[1][0] == player) && (grid[1][1] == player) && (grid[1][2] == player)) { // middle row
        return true;
    }
    else if ((grid[2][0] == player) && (grid[2][1] == player) && (grid[2][2] == player)) { // bottom row
        return true;
    }
    else if ((grid[0][0] == player) && (grid[1][0] == player) && (grid[2][0] == player)) { // left column
        return true;
    }
    else if ((grid[0][1] == player) && (grid[1][1] == player) && (grid[2][1] == player)) { // middle column
        return true;
    }
    else if ((grid[0][2] == player) && (grid[1][2] == player) && (grid[2][2] == player)) {  // right column
        return true;
    }
    else if ((grid[0][0] == player) && (grid[1][1] == player) && (grid[2][2] == player)) { // top left to down right diagonal
        return true;
    }
    else if ((grid[0][2] == player) && (grid[1][1] == player) && grid[2][0] == player) {
        return true;
    }
    else {
        return false;
    }
    return false;
}

bool get_export()
{
    char export_game = 0;
    bool first_time {true};

    std::cout << "Export game? (y/n): ";
    while (export_game != 'y' && export_game != 'n')
    {
        if (!first_time) {
            std::cout << "The option must be \'y\' or \'n\'\n";
        }

        std::cin >> export_game;

        first_time = false;

        if (std::cin.fail()) {
            clear_cin();
        }
    }
    return (export_game == 'y');
}

static void export_grid(std::ofstream &file, const char grid[3][3])
{
    file << '\n';
    for (int x = 0; x < 3; ++x)
    {
        file << ' ';
        for (int y = 0; y < 3; ++y)
        {
            file << grid[x][y];

            if (y == 2)
                continue;

            file << " | ";
        }
        if (x == 2)
            continue;
        
        file << "\n---|---|---\n";
    }
    file << '\n';
}

void export_game_f(const char grid[3][3], const bool &draw, const char &player)
{
    const char file_name[] {"TicTacToeGameExport.txt"};

    std::ofstream file(file_name, std::ios_base::app);

    // write the time time
    file << get_time(2) << '/' << get_time(3) << '/' << get_time(1) << " - " << get_time(4) << ':' << get_time(5) << '\n';

    // write the gird
    export_grid(file, grid);

    // write the winner winner / draw
    if (draw) {
        file << "Draw";
    } else {
        file << "Winner: " << player;
    }

    file << ".\n\n----------------------\n\n";

    file.close();
}

void finish_game()
{
    clear_cin();
    std::cout << "Press ENTER to exit the program.";
    std::cin.get();
}
