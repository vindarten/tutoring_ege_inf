# https://inf-ege.sdamgia.ru/problem?id=27413

def F(n):
	if n == 1:
		return 1
	elif n % 2 == 0:
		return n + F(n - 1)
	else: # if n % 2 == 1
		return 2 * F(n - 2)

print(F(26))