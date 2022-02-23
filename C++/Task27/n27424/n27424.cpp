// https://inf.reshuege.ru/problem?id=27424

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

int main()
{
	std::fstream myfile(".\\Data\\27-A_demo.txt", std::ios_base::in);
	int n;
	myfile >> n;
	int x, y, d, min = 20001, sum = 0;
	for (int i = 0; i < n; i++)
	{
		myfile >> x >> y;
		sum += std::max(x, y);
		d = std::abs(x - y);
		if (d % 3 != 0)
		{
			min = std::min(min, d);
		}
	}
	int result = sum % 3 != 0 ? sum : sum - min;
	std::cout << result << std::endl;
	return 0;
}
