# https://inf-ege.sdamgia.ru/problem?id=27891

import time

def simpleAlgo(filename):
	file = open(filename, "r")
	n = int(file.readline())
	a = []
	for line in file:
		a.append(int(line))
	x = 0
	for i, a_i in enumerate(a):
		for a_j in a[i + 1:]:
			t = a_i * a_j;
			if t % 14 == 0:
				x = max(t, x)
	return x

def onePassAlgo(filename):
	file = open(filename, "r")
	n = int(file.readline())
	max2 = max7 = max14 = maxOther = 0
	for i in range(0, n):
		t = int(file.readline())
		if t % 7 == 0 and t % 2 != 0:
			max7 = max(t, max7)
		if t % 2 == 0 and t % 7 != 0:
			max2 = max(t, max2)
		if t % 14 == 0 and t > max14:
			maxOther = max(max14, maxOther)
			max14 = t
		else:
			maxOther = max(t, maxOther)
	if max2 * max7 > max14 * maxOther:
		return max2 * max7
	else:
		return max14 * maxOther

filename = "n27891_B.txt"

print("Решение в один проход через вычисление количества чисел, делящихся на 2, 7 и 14")
start_time = time.time()
x = onePassAlgo(filename)
print("Execution time: %s seconds" % (time.time() - start_time))
print("X =", x, "\n")

print("Решение простым перебором")
start_time = time.time()
x = simpleAlgo(filename)
print("Execution time: %s seconds" % (time.time() - start_time))
print("X =", x)

