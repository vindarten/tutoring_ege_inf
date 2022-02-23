# https://inf.reshuege.ru/problem?id=27424

f = open('./Data/27-B_demo.txt')
n = int(f.readline())
mind = 20001
sum = 0
for i in range(n):
	x, y = map(int, f.readline().split())
	sum += max(x, y)
	d = abs(x - y)
	if d % 3 != 0:
		mind = min(mind, d)

if sum % 3 != 0:
	print(sum)
else:
	print(sum - mind)
