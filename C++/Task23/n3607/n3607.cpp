// https://inf-ege.sdamgia.ru/problem?id=3607

#include <iostream>

int R(int n)
{
	if (n == 50)
	{
		return 1;
	}
	else if (n > 50)
	{
		return 0;
	}
	else
	{
		return R(n + 2) + R(n * 5);
	}
}

int main()
{
	std::cout << R(2) << std::endl;
	return 0;
}