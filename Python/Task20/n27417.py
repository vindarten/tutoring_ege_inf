# https://inf.reshuege.ru/problem?id=27417

# s1 и s2 - количества камней в кучах к текущему ходу.
# k - номер хода. Ходы с четными номерами являются ходами Вани, с нечетными - Пети.
def Step(s1, s2, k):
	if k > 3:
		# Петя не выиграл за 3 хода => не выигрышная стратегия.
		return False
	if s1 + s2 + 1 >= 77 or s1 * 2 + s2 >= 77 or s1 + s2 * 2 >= 77:
		# Игрок может закончить игру в этом ходе.
		# Возвращаем true, если сейчас третий ход (второй ход Пети).
		return k == 3
	r1 = Step(s1 + 1, s2, k + 1);
	r2 = Step(s1, s2 + 1, k + 1);
	r3 = Step(s1 * 2, s2, k + 1);
	r4 = Step(s1, s2 * 2, k + 1);
	if k % 2 != 0:
		# Ход Пети.
		# Хотя бы один вариант хода Пети должен привести к победе.
		return r1 or r2 or r3 or r4
	else:
		# Ход Вани.
		# Проверяем все возможные ходы Вани, так как Петя должен выиграть при любом из них.
		return r1 and r2 and r3 and r4

for i in range(1, 68):
	if Step(7, i, 1):
		print(i)