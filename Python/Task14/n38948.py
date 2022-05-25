# https://inf-ege.sdamgia.ru/problem?id=38948

value = 4**36 + 3*4**20 + 4**15 + 2*4**7 + 49
numbers = [0]*16
while value > 0:
	numbers[value % 16] = 1
	value //= 16

print(sum(numbers))
