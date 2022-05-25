// https://inf-ege.sdamgia.ru/problem?id=37161

#include<iostream>
#include<fstream>

struct Place
{
	int row;
	int column;
};

int main()
{
	std::fstream file(".\\Data\\n37161.txt", std::ios_base::in);
	int n;
	file >> n;
	Place* places = new Place[n];
	for (int i = 0; i < n; i++)
	{
		file >> places[i].row >> places[i].column;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (places[j].row > places[j + 1].row ||
				(places[j].row == places[j + 1].row && places[j].column > places[j + 1].column))
			{
				Place t = places[j];
				places[j] = places[j + 1];
				places[j + 1] = t;
			}
		}
	}

	int maxRow = 0;
	int minColumn = 10001;
	for (int i = 0; i < n - 1; i++)
	{
		if (places[i + 1].row == places[i].row &&
			places[i + 1].column - places[i].column == 3)
		{
			if (maxRow < places[i].row)
			{
				maxRow = places[i].row;
				minColumn = places[i].column + 1;
			}
		}
	}

	std::cout << maxRow << " " << minColumn << std::endl;
	return 0;
}
