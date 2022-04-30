// https://inf.reshuege.ru/problem?id=33486

#include <iostream>

int F(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n % 3 == 0)
	{
		return n + F(n - 3);
	}
	else // if(n % 3 != 0)
	{
		return n + F(n - (n % 3));
	}
}

int main()
{
	int r = F(26);
	std::cout << r << std::endl;
	return 0;
}