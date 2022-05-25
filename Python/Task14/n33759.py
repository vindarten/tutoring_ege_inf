# https://inf-ege.sdamgia.ru/problem?id=33759

for x in range(1000):
	value = 216**5 + 6**3 - 1 - x
	count = 0
	while value > 0:
		if value % 6 == 5:
			count += 1
		value //= 6
	if count == 12:
		print(x)
		break
