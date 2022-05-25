# https://inf-ege.sdamgia.ru/problem?id=3607

def R(n):
	if n > 50:
		return 0
	elif n == 50:
		return 1
	else: # n < 50
		return R(n + 2) + R(n * 5)

print(R(2))