# https://inf-ege.sdamgia.ru/problem?id=45248

value = 7*512**1912 + 6*64**1954 - 5*8**1991 - 4*8**1980 - 2022
count = 0
while value > 0:
	if value % 8 == 7:
		count += 1
	value //= 8

print(count)
