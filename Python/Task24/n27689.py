# https://inf-ege.sdamgia.ru/problem?id=27689

file = open("n27689.txt", "r")
len = maxLen = 0
while cur := file.read(1): 
	if (cur == 'X' and len % 3 == 0) or (cur == 'Y' and len % 3 == 1) or (cur == 'Z' and len % 3 == 2):
		len += 1
		maxLen = max(len, maxLen)
	elif cur == 'X':
		len = 1
	else:
		len = 0
print(maxLen)