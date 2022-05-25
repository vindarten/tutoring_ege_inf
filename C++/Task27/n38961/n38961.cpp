// https://inf-ege.sdamgia.ru/problem?id=38961

#include <iostream>
#include <fstream>

int main()
{
	std::fstream file(".\\Data\\n38961_B.txt", std::ios_base::in);

	const int k = 10;
	int minSum[k];
	int maxSum[k];
	for (int i = 0; i < k; i++)
	{
		minSum[i] = INT_MAX;
		maxSum[i] = INT_MIN;
	}
	int x, curSum = 0, countEven = 0;
	file >> x; // Пропускаем количество чисел.
	while (file >> x)
	{
		curSum += x;
		if (x % 2 == 0)
		{
			countEven++;
		}
		minSum[countEven % 10] = std::min(curSum, minSum[countEven % 10]);
		maxSum[countEven % 10] = std::max(curSum, maxSum[countEven % 10]);
	}
	int answer = maxSum[0];
	for(int i = 1; i <= countEven % 10; i++)
	{
		answer = std::max(maxSum[i] - minSum[i], answer);
	}
	std::cout << answer << std::endl;
	return 0;
}
