# https://inf-ege.sdamgia.ru/problem?id=36000

import time
import itertools

# Самое простое решение задачи заключается в переборе всех возможных пар и поиске суммы пары в массиве.
# Без дополнительной оптимизации сложность такого подхода равна O(n^3), что, вероятнее всего,
# будет неприемлемо в условиях экзамена (слишком долго). На сайте Решу ЕГЭ предлагается решение, 
# в котором массив предварительно сортируется, а для поиска суммы пары применяется бинарный поиск,
# сложность которого O(1+log(n)). Итоговая сложность такого подхода O(n^2 * log(n)), что лучше, чем O(n^3).
# Здесь же представлены решения, сложность которых равна O(n^2).

# Решение основано на использовании множества для поиска суммы пары.
def useSet(filename):
	file = open(filename, "r")
	n = int(next(file))
	# Создаем множество.
	s = set()
	# Читаем числа из файла и добавляем в множество. Сложность O(n).
	for line in file:
		# Добавляем число в множество. Сложность O(1).
		s.add(int(line))
	count = 0
	maxSum = 0
	# Перебираем все возможные пары элементов в s. Сложность O(n^2).
	for pair in itertools.combinations(s, 2):
		sum = pair[0] + pair[1]
		# Проверяем делимость суммы на 1 (четное + нечетное = нечетное).
		if sum % 2 == 1:
			# Ищем сумму в множестве. Сложность O(1).
			if sum in s:
				count = count + 1
				maxSum = max(sum, maxSum)
	return count, maxSum

# Решение основано на использовании двух указателей для поиска пар.
def useTwoPointers(a):
	file = open(filename, "r")
	n = int(next(file))
	a = []
	# Читаем числа из файла в список. Сложность O(n).
	for line in file:
		a.append(int(line))
	# Сортируем числа в списке по возрастанию. Сложность O(n*log(n)).
	a.sort()
	count = 0
	maxSum = 0
	# Вместо перебора всех пар и поиска суммы в списке будем брать
	# число из списка и искать все пары, сумма которых равна этому числу.
	# item - число, для которого будем искать пары, y - его индекс в списке.
	for y, item in enumerate(a):
		# Проверяем делимость числа на 1 (четное + нечетное = нечетное).
		if item % 2 == 0:
			continue
		# Так как список отсортирован по возрастанию, то пары, сумма которых равна item,
		# состоят из чисел, расположеных до item.
		# Пусть i - индекс первого элемента в списке, а j - индекс элемента до item.
		# Будем cдивагать указатели навстречу друг другу, проверяя, образуют ли
		# соответствующие элементы пару с суммой, равной item.
		i = 0
		j = y - 1
		while i < j:
			sum = a[i] + a[j]
			if sum == item:
				# Нашли подходящую пару.
				count += 1
				maxSum = max(sum, maxSum)
				# Сдвинем индексы, чтобы взять следующие числа для пары.
				i += 1
				j -= 1
			elif sum < item:
				# Сумма чисел в паре слишком маленькая. Сдвинем левый индекс на один
				# элемент вправо, тем самым взяв первое число больше.
				i += 1
			else: # if sum > item
				# Сумма чисел в паре слишком большая. Сдвинем правый индекс на один
				# элемент влево, тем самым взяв второе число меньше.
				j -= 1
		# Примечание: вместо доступа к элементам списка по индексу можно 
		# использовать итераторы. Скорость работы будет быстрее.
	return count, maxSum

filename = "n36000.txt"

print("Решение с использованием множества для поиска суммы пары")
start_time = time.time()
count, maxSum = useSet(filename)
print("Execution time: %s seconds" % (time.time() - start_time))
print("count =", count, "maxSum =", maxSum, "\n")

print("Решение с использованием двух указателей для поиска пар")
start_time = time.time()
count, maxSum = useTwoPointers(filename)
print("Execution time: %s seconds" % (time.time() - start_time))
print("count =", count, "maxSum =", maxSum)
