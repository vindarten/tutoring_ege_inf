# https://inf.reshuege.ru/problem?id=38940

count = 0
for i in range(1000000):
	s = i
	s = 3 * (s // 10)
	n = 1
	while s < 221:
		s = s + 13
		n = n * 2
	if n == 128:
		count += 1
print(count)