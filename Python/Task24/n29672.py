# https://inf-ege.sdamgia.ru/problem?id=29672

file = open("n29672.txt", "r")
count = 0
for str in file:
	if str.count('A') < str.count('E'):
		count += 1
print(count)