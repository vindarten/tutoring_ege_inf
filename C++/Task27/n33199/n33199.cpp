// https://inf-ege.sdamgia.ru/problem?id=33199

#include <iostream>
#include <fstream>

int main()
{
	std::fstream file(".\\Data\\n33199_B.txt", std::ios_base::in);

	int x, y, z;
	int min = 0, med = 0, max = 0, minDif = 100001;
	int sum1 = 0, sum2 = 0, sum3 = 0;
	file >> x; // Пропускаем количество троек.
	while (file >> x >> y >> z)
	{
		max = std::max(x, std::max(y, z));
		min = std::min(x, std::min(y, z));
		med = (x + y + z) - (max + min);
		sum1 += min;
		sum2 += med;
		sum3 += max;
		if ((max - med) % 2 == 1)
		{
			minDif = std::min(max - med, minDif);
		}
		if ((max - min) % 2 == 1)
		{
			minDif = std::min(max - min, minDif);
		}
	}
	if ((sum1 - sum2) % 2 == 0)
	{
		sum3 -= minDif;
	}
	std::cout << sum3 << std::endl;
	return 0;
}