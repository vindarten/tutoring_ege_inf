# https://inf.reshuege.ru/problem?id=13579

def R(n, k):
	if n == k:
		return 1
	elif n > k:
		return 0
	else:
		return R(n + 1, k) + R(n + 2, k) + R(n + 3, k)

r1 = R(1, 8);
r2 = R(8, 15);
print(r1 * r2)
