#include <bits/stdc++.h>

using namespace std;

//The Function that set the map of the Matrix(game map)
//Number 100 in this codes means Bomb
//ERRORS: SomeTimes this algorithm generates 0 bombs and Sometimes it Doesn't show the True Number of the Bombs around the home
static void set_map(int a, int b)
{
	srand(time(0));
	int m[a][b], s, i2, j2;

	for(int i = 0; i < a; i++)
	{
		i2 = rand() % a;
		j2 = rand() % b;
		for(int j = 0; j < b; j++)
			if(i == i2 && j == j2)
				m[i][j] = 100;
	}

	//show the Number of Bombs around the home
	for(int i = 0; i < a; i++)
	{
		s = 0;
		for(int j = 0; j < b; j++)
		{
			s = 0;
			if(m[i][j] != 100)
			{
				if(m[i][j + 1] == 100)
					s++;
				if(m[i][j - 1] == 100)
					s++;
				if(m[i + 1][j] == 100)
					s++;
				if(m[i - 1][j] == 100)
					s++;

				m[i][j] = s;
			}
		}
	}

	//Showing the map in output
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < b; j++)
			cout << m[i][j] << "\t";
		cout << endl;
	}
}

int main()
{
	int a, b;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	set_map(a, b);
	return 0;
}
