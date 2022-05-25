# https://inf-ege.sdamgia.ru/problem?id=37161

file = open("n37161.txt", "r")
n = int(file.readline())
places = []
for line in file:
	places.append([int(x) for x in line.split()])
places.sort()

maxRow = 0
minColumn = 10001
for i in range(n - 1):
	if places[i + 1][0] == places[i][0] and places[i + 1][1] - places[i][1] == 3:
		if maxRow < places[i][0]:
			maxRow = places[i][0]
			minColumn = places[i][1] + 1

print(maxRow, minColumn)