// https://inf-ege.sdamgia.ru/problem?id=36000

#include <iostream>
#include <fstream>
#include <chrono>

// Самое простое решение задачи заключается в переборе всех возможных пар и поиске суммы пары в массиве.
// Без дополнительной оптимизации сложность такого подхода равна O(n ^ 3), что, вероятнее всего,
// будет неприемлемо в условиях экзамена(слишком долго).На сайте Решу ЕГЭ предлагается решение,
// в котором массив предварительно сортируется, а для поиска суммы пары применяется бинарный поиск,
// сложность которого O(1 + log(n)).Итоговая сложность такого подхода O(n ^ 2 * log(n)), что лучше, чем O(n ^ 3).
// Здесь же представлено решение, сложность которого равна O(n ^ 2).

// Решение основано на использовании двух указателей для поиска пар.
// filename - имя файла с входными данными,
// count и maxSum - переменные, через которые возвращаются количество пар и наибольшая сумма.
void useTwoPointers(const char* filename, int& count, int& maxSum)
{
	std::fstream file(filename, std::ios_base::in);
	int n;
	file >> n;
	int* a = new int[n];
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

	count = 0;
	maxSum = 0;
	// Вместо перебора всех пар и поиска суммы в массиве будем брать число из массива и искать все пары,
	// сумма которых равна этому числу.
	// item - число, для которого будем искать пары, y - его индекс в массиве.
	for (int y = 0; y < n; y++)
	{
		int item = a[y];
		// Проверяем делимость числа на 1 (четное + нечетное = нечетное).
		if (item % 2 == 0)
		{
			continue;
		}
		// Так как массив отсортирован по возрастанию, то пары, сумма которых равна item,
		// состоят из чисел, расположеных до item.
		// Пусть i - индекс первого элемента в массиве, а j - индекс элемента до item.
		// Будем cдивагать указатели навстречу друг другу, проверяя, образуют ли
		// соответствующие элементы пару с суммой, равной item.
		int i = 0;
		int j = y - 1;
		while (i < j)
		{
			int sum = a[i] + a[j];
			if (sum == item)
			{
				// Нашли подходящую пару.
				count++;
				maxSum = std::max(sum, maxSum);
				// Сдвинем индексы, чтобы взять следующие числа для пары.
				i++;
				j--;
			}
			else if (sum < item)
			{
				// Сумма чисел в паре слишком маленькая. Сдвинем левый индекс на один
				// элемент вправо, тем самым взяв первое число больше.
				i++;
			}
			else // if (sum > item)
			{
				// Сумма чисел в паре слишком большая. Сдвинем правый индекс на один
				// элемент влево, тем самым взяв второе число меньше.
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