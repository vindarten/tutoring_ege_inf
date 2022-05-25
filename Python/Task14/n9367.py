# https://inf-ege.sdamgia.ru/problem?id=9367

value = 9**8 + 3**5 - 9
count = 0
while value > 0:
	if value % 3 == 2:
		count += 1
	value //= 3

print(count)