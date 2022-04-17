// https://inf-ege.sdamgia.ru/problem?id=27891

#include <iostream>
#include <fstream>
#include <chrono>

int simpleAlgo(const char* filename)
{
	std::fstream file(filename, std::ios_base::in);
	int n;
	file >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		file >> a[i];
	}
	int x = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int t = a[i] * a[j];
			if (t % 14 == 0)
			{
				x = std::max(t, x);
			}
		}
	}
	return x;
}

int onePassAlgo(const char* filename)
{
	std::fstream file(filename, std::ios_base::in);
	int n;
	file >> n;
	int max2 = 0, max7 = 0, max14 = 0, maxOther = 0, t;
	for (int i = 0; i < n; i++)
	{
		file >> t;
		if (t % 7 == 0 && t % 2 != 0)
		{
			max7 = std::max(t, max7);
		}
		if (t % 2 == 0 && t % 7 != 0)
		{
			max2 = std::max(t, max2);
		}
		if (t % 14 == 0 && t > max14)
		{
			maxOther = std::max(max14, maxOther);
			max14 = t;
		}
		else
		{
			maxOther = std::max(t, maxOther);
		}
	}
	if (max2 * max7 > max14 * maxOther)
	{
		return max2 * max7;
	}
	else
	{
		return max14 * maxOther;
	}
}

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using std::chrono::steady_clock;
using std::cout;
using std::endl;

int main()
{
	const char* filename = ".\\Data\\27-B_2.txt";
	{
		cout << "Решение в один проход через вычисление количества чисел, делящихся на 2, 7 и 14" << endl;
		steady_clock::time_point time_start = high_resolution_clock::now();
		int x = onePassAlgo(filename);
		steady_clock::time_point time_end = high_resolution_clock::now();
		milliseconds ms = duration_cast<milliseconds>(time_end - time_start);
		cout << "Execution time: " << ms.count() / 1000.0 << " seconds" << endl;
		cout << "X = " << x << endl << endl;
	}

	{
		cout << "Решение простым перебором" << endl;
		steady_clock::time_point time_start = high_resolution_clock::now();
		int x = simpleAlgo(filename);
		steady_clock::time_point time_end = high_resolution_clock::now();
		milliseconds ms = duration_cast<milliseconds>(time_end - time_start);
		cout << "Execution time: " << ms.count() / 1000.0 << " seconds" << endl;
		cout << "X = " << x << endl;
	}
	
	return 0;
}