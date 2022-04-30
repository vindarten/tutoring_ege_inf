// https://inf.reshuege.ru/problem?id=13579

#include <iostream>

int R(int n, int k)
{
	if (n == k)
	{
		return 1;
	}
	else if (n > k)
	{
		return 0;
	}
	else
	{
		return R(n + 1, k) + R(n + 2, k) + R(n + 3, k);
	}
}

int main()
{
	int r1 = R(1, 8);
	int r2 = R(8, 15);
	std::cout << r1 * r2 << std::endl;
	return 0;
}