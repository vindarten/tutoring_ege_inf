// https://inf-ege.sdamgia.ru/problem?id=27267

#include <iostream>

int R(int n, int k, int y)
{
	if (n == y)
	{
		return 0;
	}
	else if (n == k)
	{
		return 1;
	}
	else if (n > k)
	{
		return 0;
	}
	return R(n + 1, k, y) + R(n + 2, k, y) + R(n * 3, k, y);
}

int main()
{
	int r1 = R(1, 10, 13);
	int r2 = R(10, 15, 13);
	std::cout << r1 * r2 << std::endl;
	return 0;
}