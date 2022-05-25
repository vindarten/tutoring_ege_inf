# https://inf-ege.sdamgia.ru/problem?id=7761

value = 4**2020 + 2**2017 - 15
count = 0
while value > 0:
	if value % 2 == 1:
		count += 1
	value //= 2

print(count)