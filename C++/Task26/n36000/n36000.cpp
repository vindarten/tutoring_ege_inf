// https://inf-ege.sdamgia.ru/problem?id=36000

#include <iostream>
#include <fstream>
#include <chrono>

// ����� ������� ������� ������ ����������� � �������� ���� ��������� ��� � ������ ����� ���� � �������.
// ��� �������������� ����������� ��������� ������ ������� ����� O(n ^ 3), ���, ��������� �����,
// ����� ����������� � �������� ��������(������� �����).�� ����� ���� ��� ������������ �������,
// � ������� ������ �������������� �����������, � ��� ������ ����� ���� ����������� �������� �����,
// ��������� �������� O(1 + log(n)).�������� ��������� ������ ������� O(n ^ 2 * log(n)), ��� �����, ��� O(n ^ 3).
// ����� �� ������������ �������, ��������� �������� ����� O(n ^ 2).

// ������� �������� �� ������������� ���� ���������� ��� ������ ���.
// filename - ��� ����� � �������� �������,
// count � maxSum - ����������, ����� ������� ������������ ���������� ��� � ���������� �����.
void useTwoPointers(const char* filename, int& count, int& maxSum)
{
	std::fstream file(filename, std::ios_base::in);
	int n;
	file >> n;
	int* a = new int[n];
	// ������ ����� �� ����� � ������. ��������� O(n).
	for (int i = 0; i < n; i++)
	{
		file >> a[i];
	}
	// ��������� ����� � ������� �� ����������� ����� ������� ����� ���������� ���������. ��������� O(n^2).
	// ���������������� ������ ���� ���������� ����� ���������� �����:
	// https://github.com/vindarten/tutoring_kuzn_ekaterina/blob/main/Lab04_05_Bubble/Lab04_05_Bubble/main.c
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int x = a[j];
				a[j] = a[j + 1];
				a[j + 1] = x;
			}
		}
	}

	count = 0;
	maxSum = 0;
	// ������ �������� ���� ��� � ������ ����� � ������� ����� ����� ����� �� ������� � ������ ��� ����,
	// ����� ������� ����� ����� �����.
	// item - �����, ��� �������� ����� ������ ����, y - ��� ������ � �������.
	for (int y = 0; y < n; y++)
	{
		int item = a[y];
		// ��������� ��������� ����� �� 1 (������ + �������� = ��������).
		if (item % 2 == 0)
		{
			continue;
		}
		// ��� ��� ������ ������������ �� �����������, �� ����, ����� ������� ����� item,
		// ������� �� �����, ������������ �� item.
		// ����� i - ������ ������� �������� � �������, � j - ������ �������� �� item.
		// ����� c�������� ��������� ��������� ���� �����, ��������, �������� ��
		// ��������������� �������� ���� � ������, ������ item.
		int i = 0;
		int j = y - 1;
		while (i < j)
		{
			int sum = a[i] + a[j];
			if (sum == item)
			{
				// ����� ���������� ����.
				count++;
				maxSum = std::max(sum, maxSum);
				// ������� �������, ����� ����� ��������� ����� ��� ����.
				i++;
				j--;
			}
			else if (sum < item)
			{
				// ����� ����� � ���� ������� ���������. ������� ����� ������ �� ����
				// ������� ������, ��� ����� ���� ������ ����� ������.
				i++;
			}
			else // if (sum > item)
			{
				// ����� ����� � ���� ������� �������. ������� ������ ������ �� ����
				// ������� �����, ��� ����� ���� ������ ����� ������.
				j--;
			}
		}
	}
}

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using std::chrono::steady_clock;

int main()
{
	steady_clock::time_point t1 = high_resolution_clock::now();
	int count = 0;
	int maxSum = 0;
	useTwoPointers(".\\Data\\inf_26_04_21_26.txt", count, maxSum);
	steady_clock::time_point t2 = high_resolution_clock::now();
	milliseconds ms_int = duration_cast<milliseconds>(t2 - t1);
	std::cout << "Execution time: " <<  ms_int.count() / 1000.0 << " seconds" << std::endl;
	std::cout << "count = " << count << " maxSum = " << maxSum << std::endl;
	return 0;
}