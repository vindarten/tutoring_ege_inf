# https://inf-ege.sdamgia.ru/problem?id=40740

file = open("n40740.txt", "r")
curLen = maxLen = countE = 0
while x := file.read(1): 
	if x == 'A':
		curLen = 0
		countE = 0
	else:
		curLen += 1
		if x == 'E':
			countE += 1
	if countE >= 3:
		maxLen = max(curLen, maxLen)
print(maxLen)