// https://inf-ege.sdamgia.ru/problem?id=36861

#include <iostream>

// ќформлено в виде функции, чтобы можно было использовать return
// дл€ выхода из всех вложенных циклов
int F()
{
	for (int i = 1; i < 10000; i++)
	{
		for (int j = 1; j < 10000; j++)
		{
			int s, x, n;
			x = i;
			s = j;
			s = 100 * s + x;
			n = 1;
			while (s < 2021) {
				s = s + 5 * n;
				n = n + 1;
			}
			if (n == 17)
			{
				return i;
			}
		}
	}
	return -1;
}

int main()
{
	std::cout << F() << std::endl;
	return 0;
}