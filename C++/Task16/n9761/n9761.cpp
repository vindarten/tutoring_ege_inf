// https://inf-ege.sdamgia.ru/problem?id=9761

#include <iostream>

// Нужно объявить функцию G(int) до первого использования.
int G(int n);

int F(int n)
{
	if (n > 2)
	{
		return F(n - 1) + G(n - 2);
	}
	else
	{
		return 1;
	}
}

int G(int n)
{
	if (n > 2)
	{
		return G(n - 1) + F(n - 2);
	}
	else
	{
		return 1;
	}
}

int main()
{
	std::cout << F(7) << std::endl;
	return 0;
}