# https://inf.reshuege.ru/problem?id=36861

# Оформлено в виде функции, чтобы можно было использовать return
# для выхода из всех вложенных циклов
def F():
	for i in range(1, 10000):
		x = i
		for j in range(1, 10000):
			s = j
			s = 100*s + x
			n = 1
			while s < 2021:
				s = s + 5*n
				n = n + 1
			if n == 17:
				return i
	return -1

print(F())