# https://inf-ege.sdamgia.ru/problem?id=28130

import time

def simpleAlgo(filename):
	file = open(filename, "r")
	n = int(file.readline())
	a = []
	for line in file:
		a.append(int(line))
	count = 0
	for i, a_i in enumerate(a):
		for a_j in a[i + 1:]:
			if (a_i + a_j) % 80 == 0 and (a_i > 50 or a_j > 50):
				count += 1
	return count

def onePassAlgo(filename):
	file = open(filename, "r")
	n = int(file.readline())
	m = 80
	a = [0] * m
	b = [0] * m
	max2 = max7 = max14 = maxOther = 0
	for i in range(0, n):
		t = int(file.readline())
		if t > 50:
			b[t % m] += 1
		else:
			a[t % m] += 1
	count = 0
	for i in range(1, 40):
		count += a[i] * b[m - i] + a[m - i] * b[i] + b[i] * b[m - i]
	count += a[0] * b[0] + b[0] * (b[0] - 1) // 2
	count += a[40] * b[40] + b[40] * (b[40] - 1) // 2
	return count

filename = "n28130_B.txt"

print('''Решение в один проход через подсчет количества чисел,
дающих опредленные остатки при делении на 80''')
start_time = time.time()
count = onePassAlgo(filename)
print("Execution time: %s seconds" % (time.time() - start_time))
print("count =", count, "\n")

print("Решение простым перебором")
start_time = time.time()
count = simpleAlgo(filename)
print("Execution time: %s seconds" % (time.time() - start_time))
print("count =", count)

