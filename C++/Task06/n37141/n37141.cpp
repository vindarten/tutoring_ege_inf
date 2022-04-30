// https://inf-ege.sdamgia.ru/problem?id=37141

#include <iostream>

using namespace std;

int main()
{
	int max_i = -1001;
	for (int i = -1000; i < 1000; i++)
	{
		int n, s;
		n = 1024;
		s = i;
		while (s >= 5) {
			s = s - 5;
			n = n / 2;
		}
		if (n == 64)
		{
			max_i = i;
		}
	}
	std::cout << max_i << std::endl;
	return 0;
}