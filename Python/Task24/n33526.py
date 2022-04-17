# https://inf-ege.sdamgia.ru/problem?id=33526

file = open("n33526.txt", "r")
c1 = file.read(1)
c2 = file.read(1)
count = {}
while c3 := file.read(1): 
	if c1 == c3:
		count[c2] = count.get(c2, 0) + 1
	c1 = c2
	c2 = c3
print(max(count, key=count.get))