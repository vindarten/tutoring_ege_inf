// https://inf-ege.sdamgia.ru/problem?id=40981

#include <iostream>

using namespace std;

int main()
{
	int max_i = -1;
	for (int i = 0; i < 1000000; i++)
	{
		int s, n;
		s = i;
		s = s / 10;
		n = 1;
		while (s < 221) {
			if (n % 2 == 0)
				s = s + 13;
			n = n + 5;
		}
		if (n == 121)
		{
			max_i = i;
		}
	}
	std::cout << max_i << std::endl;
	return 0;
}