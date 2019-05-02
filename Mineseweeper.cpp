#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int m[9][9];            //m is the matrix that the facts are there
int computer[9][9];  //computer matrix is the matrix that is shown to the user
bool end_game = false;
int cnt = 10;


void show_map()            //showing the computer matrix to the screen
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(computer[i][j] == 100)
                cout << "*\t";
            else
                if(computer[i][j] == 111)
                    cout << "F\t";
                else
                    cout << computer[i][j] << "\t";
        }
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

    bool is_run(int x, int y)
    {
        if(m[x][y] == 100)         // if that home is bomb -> returns true, else false
            return false;
        else
            return true;
    }

    void open(int x, int y)       //Openning the x, y position
    {
        if(is_run(x, y))
        {
            computer[x][y] = m[x][y];

            ///a1 Border
            for(int i = x + 1; i <= 9; i++)
            {
                if(is_run(i, y))
                {
                    computer[i][y] = m[i][y];
                    //break;
                }
                else
                {
                    computer[i - 1][y] = m[i - 1][y];
                    break;
                }
            }
            ///Finish a1 Border


            ///a2 Border
            for(int i = x - 1; i >= 0; i--)
            {
                if(is_run(i, y))
                {
                    computer[i][y] = m[i][y];
                    //break;
                }
                else
                {
                    computer[i][y + 1] = m[i][y + 1];
                    break;
                }
            }
            ///Finish a2 Border

            ///a3 Border
            for(int i = y + 1; i <= 9; i++)
            {
                if(is_run(x, i))
                {
                    computer[x][i] = m[x][i];
                    //break;
                }
                else
                {
                    computer[x][i - 1] = m[x][i];
                    break;
                }
            }
            ///Finsih a3 Border

            ///a4 Border
            for(int i = y - 1; i >= 0; i--)
            {
                if(is_run(x, i))
                {
                    computer[x][i] = m[x][i];
                    //break;
                }
                else
                {
                    computer[x][i + 1] = m[x][i + 1];
                    break;
                }
            }
        }
        else
            end_game = true;


        //show_map();
    }


    void flag(int x, int y)
    {
        ///one time minus
        static int cnt = 0;
        static int x2, y2;

        computer[x][y] = 111;
        if(cnt == 0 && x != x2 && y != y2)
        {
            if(computer[x][y + 1] < 5)
                computer[x][y + 1]--;
            if(computer[x][y - 1] < 5)
                computer[x][y - 1]--;
            if(computer[x + 1][y] < 5)
                computer[x + 1][y]--;
            if(computer[x - 1][y] < 5)
                computer[x - 1][y]--;
        }

        cnt++;
        x2 = x;
        y2 = y;

        //show_map();
    }
};


class solver : public game
{
public:
    void solve(int x, int y)
    {

        int s = 0;
        double home[4];

        for(int i = 0; i < 4; i++)
            home[i] = -1;

        if(computer[x][y + 1] == 100 || computer[x][y + 1] == 111)
        {
            home[0] = 0;
            s++;
        }

        if(computer[x][y - 1] == 100 || computer[x][y - 1] == 111)
        {
            home[1] = 0;
            s++;
        }

        if(computer[x + 1][y] == 100 || computer[x + 1][y] == 111)
        {
            home[2] = 0;
            s++;
        }
        if(computer[x - 1][y] == 100 || computer[x - 1][y] == 111)
        {
            home[3] = 0;
            s++;
        }

        /*for(int i = 3; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(!((i == 0 && j == 0) || (i == 0 && j == 2) || (i == 2 && j == 0) || (i == 2 && j == 2)))
                {
                    if(!(i == 1 && j == 1))
                    {

                    }
                }
            }
        }*/

        for(int i = 0; i < 4; i++)
        {
            if(home[i] != -1)
            {
                home[i] = computer[x][y] / (s * 1.0);
            }
        }

        for(int i = 0; i < 4; i++)
        {
            if(home[i] == 0)
            {
                switch(i)
                {
                case 0: open(x, y + 1); break;
                case 1: open(x, y - 1); break;
                case 2: open(x + 1, y); break;
                case 3: open(x - 1, y); break;
                }
            }

            if(home[i] == 1)
            {
                switch(i)
                {
                case 0: flag(x, y + 1); break;
                case 1: flag(x, y - 1); break;
                case 2: flag(x + 1, y); break;
                case 3: flag(x - 1, y); break;
                }
            }
        }

    }

    void start()
    {
        Sleep(1000);
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(computer[i][j] != 100 || computer[i][j] != 111)
                    solve(i, j);
            }
    }
};



int main()
{
    srand(time(NULL));    //Random seed
    string a;
    game Game;
    solver Solver;
    int cnt = 0, win = 0;

	set_map();

	system("color A");


	cout << "Hello, My name is Minesweeper solver:) and I'm a AI that solves the 9 * 9 Random table ;)\n\n";
	cout << "Some Information about the Game:\n";
    cout << "     1. * means this home is unrecognizable =)\n\n";
    cout << "     2. My speed in solving the table is about 10 seconds /) \n\n";
    cout << "     3. My Creators are Behrad Malakouti & Mohammad Erfan Kalantary :)\n\n";
    cout << "Write your name (put '*' at the end of your name) to start ;) : ";
    cin >> a;


    if(a[a.size() - 1] == '*')
    {

        for(int i = 1; i <= 27; i++)
        {
            system("cls");
            system("color D");

            if(i % 2 == 0)
                cout << "\n\n\n\n\n\n\n\n\n\n\n";
            else
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            for(int j = 1; j <= i; j++)
            {
                cout << "      ";
            }
            cout << " ***********Welcome to the Game " << a << "**********";
            Sleep(250);
        }
    }

    system("cls");
    system("color 7");

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            computer[i][j] = 100;

    show_map();
    cout << "\n\n";

    /*Game.x = rand() % 9;
    Game.y = rand() % 9;*/
    Game.x = 0;
    Game.y = 0;

    while(Game.is_run(Game.x, Game.y))
    {
        if(end_game)
        {
            system("cls");
            cout << "Hey baby!:) You losed! Try again ;)\n";
            break;
        }
        system("cls");
        //Game.x = rand() % 9;
        //Game.y = rand() % 9;
        Game.open(Game.x, Game.y);
        show_map();

        if(cnt == 10)
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    if(computer[i][j] == 100)
                        Game.open(i, j);
                }
            }
        }

        Solver.start();

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(computer[i][j] == 111 && computer[i][j] == m[i][j] + 11)
                    win++;
            }
        }

        if(win == 10)
        {
            system("cls");
            cout << "I win!!!!!!!!!!!!!!!!!!!!!!!!!!!!! :) :) :) :) :) :) :) ;) ;) ;) ;) \n\n\n\n";
            end_game = false;
            break;

        }
        ///start();
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(computer[i][j] == 111)
                    cnt++;
            }
        }

        cout << "\n\n\n\n\n";
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << m[i][j] << "\t";
            }
            cout << endl;
        }
        Sleep(10000);
    }

    if(end_game)
    {
        system("cls");
        system("Color b");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "OH, That's not good!:( I losed, Minesweeper is the Game of luck\n\n\n\n\n\n";
        Sleep(1000);



        system("cls");
        for(int i = 0; i < 9; i++)
        {
            system("color 7");
            for(int j = 0; j < 9; j++)
            {
                cout << computer[i][j] << "\t";
            }
            cout << "\n";
        }

        cout << "\n I Solved to here :) pree any key to exit...";
    }


	_getch();
}

///Make the Numebrs ok when the flags are near them! This is SOoooo Important.

