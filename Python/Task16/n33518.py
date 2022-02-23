# https://inf.reshuege.ru/problem?id=33518

def F(n):
	if n == 0:
		return 0
	elif n % 2 == 0:
		return F(n / 2)
	else:
		return 1 + F(n - 1)

i = 1
while F(i) != 12:
	i += 1
print(i)