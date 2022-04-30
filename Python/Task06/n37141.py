# https://inf.reshuege.ru/problem?id=37141

max_i = -1001
for i in range(-1000, 1000):
	n = 1024
	s = i
	while s >= 5:
		s = s - 5
		n = n // 2
	if n == 64:
		max_i = i
print(max_i)