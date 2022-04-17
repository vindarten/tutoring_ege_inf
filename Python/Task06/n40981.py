# https://inf.reshuege.ru/problem?id=40981

max_i = 0
for i in range(1000000):
	s = i
	s = s // 10
	n = 1
	while s < 221:
		if n % 2 == 0:
			s = s + 13
		n = n + 5
	if n == 121:
		max_i = i
print(max_i)
