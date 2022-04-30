// https://inf-ege.sdamgia.ru/problem?id=39763

#include <iostream>
#include <fstream>

int main()
{
	std::fstream myfile(".\\Data\\n39763.txt", std::ios_base::in);
	int x = 0, y = 0, z = 0;
	int count = 0;
	int maxSum = 0;
	myfile >> x >> y;
	while (myfile >> z)
	{
		int c = std::max(x, std::max(y, z));
		int b = std::min(x, std::min(y, z));
		int a = x + y + z - b - c;
		if (c*c < a*a + b*b)
		{
			count++;
			maxSum = std::max(x + y + z, maxSum);
		}
		x = y;
		y = z;
	}
	std::cout << "count = " << count << " maxSum = " << maxSum << std::endl;
	return 0;
}