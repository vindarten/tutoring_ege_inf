// https://inf-ege.sdamgia.ru/problem?id=27886

#include <iostream>
#include <fstream>

int main()
{
	std::fstream file(".\\Data\\27886.txt", std::ios_base::in);
	int maxSum, n;
	file >> maxSum >> n;
	int a[2000];
	// Читаем числа из файла в массив. Сложность O(n).
	for (int i = 0; i < n; i++)
	{
		file >> a[i];
	}
	// Сортируем числа в массиве по возрастанию самым простым видом сортировки пузырьком. Сложность O(n^2).
	// Оптимизированную версию этой сортировки можно посмотреть здесь:
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
	// Берем в архив самые маленькие файлы, чтобы поместилось как можно больше.
	while (curSum + a[i] <= maxSum && i < n)
	{
		curSum += a[i];
		i++;
	}
	// После цикла переменная i содержит количество файлов, попавших в архив.
	// Это и есть максимально возможное количество файлов.
	int count = i;
	// last - размер последнего файла, попавшего в массив. Это самый большой файл в массиве.
	// Попробуем среди оставшихся файлов найти файл больше и заменить.
	int last = a[i - 1];
	while (curSum - last + a[i] <= maxSum)
	{
		i++;
	}
	// После цикла переменная i содержит номер первого файла, который не поместился в архив.
	// Значит предыдущий файл помещался и имел максимально возможный размер.
	int maxSize = a[i - 1];
	std::cout << "count = " << count << " maxSize = " << maxSize << std::endl;
	return 0;
}