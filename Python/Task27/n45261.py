# https://inf-ege.sdamgia.ru/problem?id=45261

# Решение работает только для случая, когда n - четное

file = open("n45261_B.txt", "r")

n = int(file.readline())
a = []
for i in range(n):
	a.append(int(file.readline()))

cost0 = leftSum = rightSum = 0
for i in range(n // 2):
	cost0 += a[i] * i
	rightSum += a[i]
for i in range(n // 2, n):
	cost0 += a[i] * (n - i)
	leftSum += a[i]

costI = maxCost = cost0
for i in range(1, n):
	leftSum = leftSum + a[i - 1] - a[(n // 2 + i - 1) % n]
	rightSum = rightSum - a[i - 1] + a[(n // 2 + i - 1) % n]
	costI = costI + leftSum - rightSum
	maxCost = min(costI, maxCost)

print(maxCost)