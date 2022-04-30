# https://inf.reshuege.ru/problem?id=18503

def R(n, k, y):
	if n == y:
		return 0
	elif n == k:
		return 1
	elif n > k:
		return 0
	else:
		return R(n + 1, k, y) + R(n + 2, k, y) + R(n * 3, k, y)

r1 = R(1, 10, 13)
r2 = R(10, 15, 13)
print(r1 * r2)
