# https://inf.reshuege.ru/problem?id=27416

# s1 и s2 - количества камней в кучах к текущему ходу.
# k - номер хода. Ходы с четными номерами являются ходами Вани, с нечетными - Пети.
def Step(s1, s2, k):
	if k > 2:
		# Ваня не выиграл за 2 хода => не выигрышная стратегия.
		return False
	if s1 + s2 + 1 >= 77 or s1 * 2 + s2 >= 77 or s1 + s2 * 2 >= 77:
		# Игрок может закончить игру в этом ходе.
		# Возвращаем true, если сейчас второй ход (первый ход Вани).
		return k == 2
	# Перебираем все возможные варианты совершить ход.
	r1 = Step(s1 + 1, s2, k + 1)
	r2 = Step(s1, s2 + 1, k + 1)
	r3 = Step(s1 * 2, s2, k + 1)
	r4 = Step(s1, s2 * 2, k + 1)
	if k % 2 != 0:
		# Ход Пети.
		# Должен существовать хотя бы один вариант хода Пети (неудачный), при котором Ваня выиграет.
		return r1 or r2 or r3 or r4
	else:
		# Ход Вани.
		# Хотя бы один вариант хода Вани должен привести к победе.
		return r1 or r2 or r3 or r4

for i in range(1, 68):
	if Step(7, i, 1):
		# Выводим первое подходящее значение S и выходим из цикла. 
		print(i)
		break;