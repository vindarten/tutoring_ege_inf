// https://inf.reshuege.ru/problem?id=27413

#include <iostream>

int F(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n % 2 == 0)
	{
		return n + F(n - 1);
	}
	else // if(n % 2 == 1)
	{
		return 2 * F(n - 2);
	}
}

int main()
{
	int r = F(26);
	std::cout << r << std::endl;
	return 0;
}