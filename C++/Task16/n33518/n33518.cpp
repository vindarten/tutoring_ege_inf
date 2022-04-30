// https://inf.reshuege.ru/problem?id=33518

#include <iostream>

int F(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n % 2 == 0)
	{
		return F(n / 2);
	}
	else // if(n % 2 != 0)
	{
		return 1 + F(n - 1);
	}
}

int main()
{
	int i = 1;
	while (F(i) != 12)
	{
		i++;
	}
	std::cout << i << std::endl;
	return 0;
}