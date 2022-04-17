# https://inf-ege.sdamgia.ru/problem?id=27421

file = open("n27421.txt", "r")
last = file.read(1)
len = maxLen = 0
while next := file.read(1):
	if last != next:
		len += 1
		maxLen = max(len, maxLen)
	else:
		len = 1
	last = next
print(maxLen)