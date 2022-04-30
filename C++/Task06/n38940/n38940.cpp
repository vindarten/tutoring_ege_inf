// https://inf-ege.sdamgia.ru/problem?id=38940

#include <iostream>

int main()
{
	int count = 0;
	for (int i = 0; i < 1000000; i++)
	{
		int s, n;
		s = i;
		s = 3 * (s / 10);
		n = 1;
		while (s < 221) {
			s = s + 13;
			n = n * 2;
		}
		if (n == 128)
		{
			count += 1;
		}
	}
	std::cout << count << std::endl;
	return 0;
}