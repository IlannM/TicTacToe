#include <cstdio>
#include "random.hpp"
#include "functions.hpp"
#include "time.hpp"

class Bot {
private:
    char player = '\0';

public:
    int get_move(const char grid[3][3]);
    void set_player(const char &player);
    char get_player();
    void write();
};

int Bot::get_move(const char grid[3][3]) {
    int bot_move = 0;
    do {
        bot_move = get_random_num(1,9);
        printf("%d\n", bot_move);
    } while (is_taken(bot_move, grid));
    
    return bot_move;
}

// works
void Bot::set_player(const char &player)
{
    this->player = (player == 'O') ? 'X' : 'O' ;
}

char Bot::get_player()
{ return player; }


// ------------------------------------------------
class Player {
private:
    char player = '\0';
public:
    char get_player();
    void set_player(const char &player);
};

char Player::get_player()
{ return this->player; }

void Player::set_player(const char &player) {
    this->player = (player == 'O') ? 'X' : 'O' ;
}
// -------------------------------------------------

class Game {
private:
    char grid[3][3] { // 3x3 grid
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };
    
    bool won = false;
public:

};

int main(int argc, char *argv[]) {
    Game game;
    Bot bot;
    Player player;


    for (int i = 0; i < 9; ++i) {
        
        if ()
            write_to_grid(grid, player_move);
    }

    return 0;
}
