# https://inf-ege.sdamgia.ru/problem?id=38961

file = open("n38961_B.txt", "r")
k = 10
minSum = [2*10**9]*k;
maxSum = [0]*k
curSum = countEven = 0
n = int(file.readline()) # Читаем количество чисел.
for i in range(n):
	x = int(file.readline())
	curSum += x
	if x % 2 == 0:
		countEven += 1
	minSum[countEven % 10] = min(curSum, minSum[countEven % 10])
	maxSum[countEven % 10] = max(curSum, maxSum[countEven % 10])
answer = maxSum[0]
for i in range(1, countEven % 10 + 1):
	answer = max(maxSum[i] - minSum[i], answer)
print(answer)