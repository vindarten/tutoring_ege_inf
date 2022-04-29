# https://inf-ege.sdamgia.ru/problem?id=39763

file = open('n39763.txt')

count = 0
maxSum = 0
x = int(file.readline())
y = int(file.readline())
for line in file:
	z = int(line)
	c = max(x, y, z)
	b = min(x, y, z)
	a = x + y + z - b - c;
	if c*c < a*a + b*b:
		count += 1
		maxSum = max(x + y + z, maxSum)
	x = y
	y = z
print("count =", count, "maxSum =", maxSum)