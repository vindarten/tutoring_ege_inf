// https://inf-ege.sdamgia.ru/problem?id=27886

#include <iostream>
#include <fstream>

int main()
{
	std::fstream file(".\\Data\\27886.txt", std::ios_base::in);
	int maxSum, n;
	file >> maxSum >> n;
	int a[2000];
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

	int curSum = 0, i = 0;
	// ����� � ����� ����� ��������� �����, ����� ����������� ��� ����� ������.
	while (curSum + a[i] <= maxSum && i < n)
	{
		curSum += a[i];
		i++;
	}
	// ����� ����� ���������� i �������� ���������� ������, �������� � �����.
	// ��� � ���� ����������� ��������� ���������� ������.
	int count = i;
	// last - ������ ���������� �����, ��������� � ������. ��� ����� ������� ���� � �������.
	// ��������� ����� ���������� ������ ����� ���� ������ � ��������.
	int last = a[i - 1];
	while (curSum - last + a[i] <= maxSum)
	{
		i++;
	}
	// ����� ����� ���������� i �������� ����� ������� �����, ������� �� ���������� � �����.
	// ������ ���������� ���� ��������� � ���� ����������� ��������� ������.
	int maxSize = a[i - 1];
	std::cout << "count = " << count << " maxSize = " << maxSize << std::endl;
	return 0;
}