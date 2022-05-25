// https://inf-ege.sdamgia.ru/problem?id=29207

#include <iostream>

int R(int n, int k, int y)
{
	if (n == y)
	{
		return 0;
	}
	else if (n > k)
	{
		return 0;
	}
	else if (n == k)
	{
		return 1;
	}
	else
	{
		return R(n + 1, k, y) + R(n * 2, k, y);
	}
}

int main()
{
	int r1 = R(2, 11, 12) * R(11, 24, 12);
	int r2 = R(2, 12, 11) * R(12, 24, 11);
	std::cout << r1 + r2 << std::endl;
	return 0;
}