# https://inf-ege.sdamgia.ru/problem?id=29207

def R(n, k, y):
	if n == y:
		return 0
	elif n > k:
		return 0
	elif n == k:
		return 1
	else:
		return R(n + 1, k, y) + R(n * 2, k, y)

r1 = R(2, 11, 12) * R(11, 24, 12)
r2 = R(2, 12, 11) * R(12, 24, 11)
print(r1 + r2)