# https://inf-ege.sdamgia.ru/problem?id=38589

value = 3*4**38 + 2*4**23 + 4**20 + 3*4**5 + 2*4**4 + 1
count = 0
while value > 0:
	if value % 16 == 0:
		count += 1
	value //= 16

print(count)
