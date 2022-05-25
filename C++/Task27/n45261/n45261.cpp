// https://inf-ege.sdamgia.ru/problem?id=45261

#include <iostream>
#include <fstream>

// Решение работает только для случая, когда n - четное
int main()
{
	std::fstream file(".\\Data\\n45261_B.txt", std::ios_base::in);

	int n;
	file >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		file >> a[i];
	}

	long long cost0 = 0, leftSum = 0, rightSum = 0;
	for (int i = 0; i < n / 2; i++)
	{
		cost0 += a[i] * i;
		rightSum += a[i];
	}
	for (int i = n / 2; i < n; i++)
	{
		cost0 += a[i] * (n - i);
		leftSum += a[i];
	}

	long long costI = cost0, maxCost = cost0;
	for (int i = 1; i < n; i++)
	{
		leftSum = leftSum + a[i - 1] - a[(n / 2 + i - 1) % n];
		rightSum = rightSum - a[i - 1] + a[(n / 2 + i - 1) % n];
		costI = costI + leftSum - rightSum;
		maxCost = std::min(costI, maxCost);
	}
	std::cout << maxCost << std::endl;
	return 0;
}