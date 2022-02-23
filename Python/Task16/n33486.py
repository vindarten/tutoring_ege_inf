# https://inf-ege.sdamgia.ru/problem?id=33486

def F(n):
	if n == 0:
		return 0
	elif n % 3 == 0:
		return n + F(n - 3)
	else:
		return n + F(n - (n % 3))

print(F(26))