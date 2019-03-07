#include <iostream>
#include <stdlib.h>
#include "game.h"

using namespace std;

class Player
{
    unsigned x;
    unsigned y;

    public:
        Player()
        {
            x = 6;
            y = 6;
        }
        Player(unsigned x,unsigned y)
        {
            this->x = x;
            this->y = y;
        }
        unsigned getX()
        {
            return x;
        }

        unsigned getY()
        {
            return y;
        }

        void moveUp()
        {
            if (y != 0)
                --y;
        }
        void moveDown()
        {
            if (y != MAP_SIZE-1)
                ++y;
        }
        void moveLeft()
        {
            if (x != 0)
                --x;
        }
        void moveRight()
        {
            if (x != MAP_SIZE-1)
                ++x;
        }
};

void printField(Player &pl,Player &enemy)
{
    for (unsigned u = 0;u < MAP_SIZE;u++)
        cout << "-";
    cout <<endl;
    for (unsigned y = 0;y < MAP_SIZE;y++)
    {
        for (unsigned x = 0;x < MAP_SIZE;x++)
        {
            if (pl.getX() == x && pl.getY() == y)
                cout << 'O';
            else if (enemy.getX() == x && enemy.getY() == y)
                cout << 'X';
            else
                cout << '#';
        }
        cout << endl;
    }    
}
void printfWelcomeMessage()
{
    cout << "####WELCOME TO THE GAME####" << endl;
    cout << "####O - CHARACTER####" << endl;
    cout << "####X - ENEMY####" << endl;
    cout << "####TO QUIT USE KEY 'q'####" << endl;
    cout << "####TO MOVE CHARACTER UP USE KEY 'w'####" << endl;
    cout << "####TO MOVE CHARACTER LEFT USE KEY 'a'####" << endl;
    cout << "####TO MOVE CHARACTER DOWN USE KEY 's'####" << endl;
    cout << "####TO MOVE CHARACTER RIGHT USE KEY 'd'####" << endl;
    cout << "####GOOD LUCK AND HAVE SOME FUN####" << endl;
}

void moveEnemy(Player &enemy,Player &pl)
{
    if (pl.getX() > enemy.getX())
        enemy.moveRight();
    else if (pl.getX() < enemy.getX())
        enemy.moveLeft();
    else if (pl.getY() < enemy.getY())
        enemy.moveUp();
    else if (pl.getY() > enemy.getY())
        enemy.moveDown();
}

void quit()
{
    resetTermios();
    std::exit(0);
}

void check_status(Player &pl,Player &enemy)
{
    if (enemy.getX() == pl.getX() && enemy.getY() == pl.getY())
    {
        cout << "YOU ARE DEAD";
        quit();
    }

}

int main()
{
    Player pl;
    Player enemy(0,0);

    char c;
    initTermios(0);
    while (true)
    {   
        check_status(pl,enemy);
        printField(pl,enemy);
        c = getchar();
        switch (c)
        {
            case 'q':
                quit();
                break;
            case 'w':
                pl.moveUp();
                break;
            case 's':
                pl.moveDown();
                break;
            case 'a':
                pl.moveLeft();
                break;
            case 'd':
                pl.moveRight();
                break;
        
            default:
                break;
        }
        moveEnemy(enemy,pl);    
    }
  
}
