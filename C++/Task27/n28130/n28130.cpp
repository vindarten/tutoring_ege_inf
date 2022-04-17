// https://inf-ege.sdamgia.ru/problem?id=28130

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
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((a[i] + a[j]) % 80 == 0 && (a[i] > 50 || a[j] > 50))
			{
				count++;
			}
		}
	}
	return count;
}

int onePassAlgo(const char* filename)
{
	std::fstream file(filename, std::ios_base::in);
	int n;
	file >> n;
	const int m = 80;
	int a[m], b[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = b[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		file >> x;
		if (x > 50)
		{
			b[x % m]++;
		}
		else
		{
			a[x % m]++;
		}
	}
	int count = 0;
	for (int i = 1; i < 40; i++)
	{
		count += a[i] * b[m - i] + a[m - i] * b[i] + b[i] * b[m - i];
	}
	count += a[0] * b[0] + b[0] * (b[0] - 1) / 2;
	count += a[40] * b[40] + b[40] * (b[40] - 1) / 2;
	return count;
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
	const char* filename = ".\\Data\\28130_B.txt";
	{
		cout << "Решение в один проход через подсчет количества чисел,";
		cout << "дающих опредленные остатки при делении на 80" << endl;
		steady_clock::time_point time_start = high_resolution_clock::now();
		int count = onePassAlgo(filename);
		steady_clock::time_point time_end = high_resolution_clock::now();
		milliseconds ms = duration_cast<milliseconds>(time_end - time_start);
		cout << "Execution time: " << ms.count() / 1000.0 << " seconds" << endl;
		cout << "count = " << count << endl << endl;
	}

	{
		cout << "Решение простым перебором" << endl;
		steady_clock::time_point time_start = high_resolution_clock::now();
		int count = simpleAlgo(filename);
		steady_clock::time_point time_end = high_resolution_clock::now();
		milliseconds ms = duration_cast<milliseconds>(time_end - time_start);
		cout << "Execution time: " << ms.count() / 1000.0 << " seconds" << endl;
		cout << "count = " << count << endl;
	}

	return 0;
}