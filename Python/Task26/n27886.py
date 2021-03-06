# https://inf-ege.sdamgia.ru/problem?id=27886

import time
import itertools

file = open("n27886.txt", "r")
maxSum, n = map(int, file.readline().split())
a = []
# Читаем числа из файла в список. Сложность O(n).
for line in file:
	a.append(int(line))
# Сортируем числа в списке по возрастанию. Сложность O(n*log(n)).
a.sort()

curSum = i = 0
# Берем в архив самые маленькие файлы, чтобы поместилось как можно больше.
while curSum + a[i] <= maxSum and i < n:
	curSum += a[i]
	i += 1
# После цикла переменная i содержит количество файлов, попавших в архив.
# Это и есть максимально возможное количество файлов.
count = i
# last - размер последнего файла, попавшего в массив. Это самый большой файл в массиве.
# Попробуем среди оставшихся файлов найти файл больше и заменить.
last = a[i - 1]
while curSum - last + a[i] <= maxSum:
	i += 1
# После цикла переменная i содержит номер первого файла, который не поместился в архив.
# Значит предыдущий файл помещался и имел максимально возможный размер.
maxSize = a[i - 1]
print("count =", count, "maxSize =", maxSize)