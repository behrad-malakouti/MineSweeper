#include <bits/stdc++.h>

using namespace std;


static void set_map()
{
	srand(time(NULL));
	int m[9][9], s, i2, j2, bomb = 0;

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

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
			if(m[i][j] != 100)
				cout << m[i][j] << "\t";
			else
				cout << "BOMB\t";
		cout << endl;
	}
}

int main()
{
	set_map();

	return 0;
}
