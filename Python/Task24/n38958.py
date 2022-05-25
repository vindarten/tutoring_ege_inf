# https://inf-ege.sdamgia.ru/problem?id=38958

file = open("n38958.txt", "r")
curLen = lenFromLastA = maxLen = 0
while x := file.read(1): 
	if x == 'A':
		curLen = lenFromLastA + 1
		lenFromLastA = 0
	else:
		curLen += 1
		lenFromLastA += 1
	maxLen = max(curLen, maxLen)
print(maxLen)