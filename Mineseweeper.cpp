#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int m[9][9];            //m is the matrix that the facts are there
int computer[9][9];  //computer matrix is the matrix that is shown to the user


void show_map()            //showing the computer matrix to the screen
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << computer[i][j] << "\t";
        cout << "\n";
    }
}

void set_map()              //Make the main map for the game randomly
{
	int s, i2, j2, bomb = 0;

	while(bomb < 10)
	{
		i2 = rand() % 9;
		j2 = rand() % 9;

		if(m[i2][j2] != 100)
		{
			m[i2][j2] = 100;
			bomb++;
		}
	}

	for(int i = 0; i < 9; i++)
	{
		s = 0;
		for(int j = 0; j < 9; j++)
		{
			s = 0;
			if(m[i][j] != 100)
			{
				if(j + 1 <= 8)
					if(m[i][j + 1] == 100)
						s++;

				if(j - 1 >= 0)
					if(m[i][j - 1] == 100)
						s++;

				if(i + 1 <= 8)
					if(m[i + 1][j] == 100)
						s++;

				if(i - 1 >= 0)
					if(m[i - 1][j] == 100)
						s++;

				m[i][j] = s;
			}
		}
	}

	return;
}

class game
{
public:
    int x, y;                   //(x, y) is the position of the home that have been selected by computer
    bool is_run()
    {
        if(m[x][y] == 100)
            return false;
        else
            return true;
    }
    void open()
    {
        computer[y][x] = m[y][x];
        if(m[y][x] == 100)
        {
            system("cls");
            cout << "I losed, I'm sorry!:( MineSweeper is the game of luck!";
            return;
        }

        for(int i = x + 1; ; i++)
        {
            if(m[y][i] != 100)
                computer[i][y] = m[i][y];
            if(m[y][i + 1] == 100)
                break;
        }
        show_map();
        return;
    }
};

class solving
{
    int start_x = 0, start_y = 0;
    void conquare()
    {
        int solve_m[3][3];
        for(int i = start_x; i <= start_x + 3; i++)
        {
            for(int j = start_x; j <= start_y + 3; j++)
            {
                solve_m[i % 3][j % 3] = computer[i][j];
            }
        }
    }

    void solve()
    {

    }

    void change()
    {

    }
};


int main()
{
    srand(time(NULL));    //Random seed
    game Game;
	set_map();

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            computer[i][j] = 1000;

        }
    }

    show_map();
    cout << "\n\n";

    Game.x = rand() % 9;
    Game.y = rand() % 9;


    if(!Game.is_run())
    {
        system("cls");
            cout << "Lose --> avali bomb";
    }
    while(Game.is_run())
    {
        system("cls");
        Game.x = rand() % 9;
        Game.y = rand() % 9;
        Game.open();
        Sleep(1000);
    }

    cout << "\n\n";

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n\n\n\n\n";

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << computer[i][j] << "\t";
        cout << "\n\n";
    }

	return 0;
}
