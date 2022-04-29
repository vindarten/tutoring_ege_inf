# https://inf-ege.sdamgia.ru/problem?id=33199

file = open("n33199_B.txt", "r")
n = int(file.readline()) # Читаем количество троек.
maxSum = otherSum = 0
minDif = 100001
for line in file:
	x, y, z = line.split()
	x, y, z = sorted([int(x), int(y), int(z)])
	maxSum += z
	otherSum += x + y
	for i in [x, y]:
		if (z - i) % 2 == 1:
			minDif = min(z - i, minDif)
if otherSum % 2 == 0:
	maxSum -= minDif
print(maxSum)