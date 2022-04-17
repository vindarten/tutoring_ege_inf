﻿# https://inf.reshuege.ru/problem?id=27804

# s - количество камней в куче к текущему ходу.
# k - номер текущего хода. Ходы с четными номерами являются ходами Вани, с нечетными - Пети.
# n - номер хода, до которого (включительно) Ваня должен выиграть.
def Step(s, k, n):
	if k > n:
		# Ваня не выиграл за n ходов => не выигрышная стратегия.
		return False
	if s + 1 >= 68 or s + 4 >= 68 or s * 5 >= 68:
		# Игрок может закончить игру в этом ходе.
		# Возвращаем true, если сейчас четный ход (первый или второй ход Пети).
		return k % 2 == 0
	r1 = Step(s + 1, k + 1, n)
	r2 = Step(s + 4, k + 1, n)
	r3 = Step(s * 5, k + 1, n)
	if k % 2 != 0:
		# Ход Пети
		# Проверяем все возможные ходы Пети, так как Ваня должен выиграть при любом из них.
		return r1 and r2 and r3
	else:
		# Ход Вани.
		# Хотя бы один вариант хода Вани должен привести к победе.
		return r1 or r2 or r3

for i in range(1, 68):
	# Ваня может выиграть вторым или четвертым ходом (своим первым или вторым),
	# но у Вани нет стратегии, которая позволит ему гарантированно выиграть вторым ходом (своим первым).
	if Step(i, 1, 4) and not Step(i, 1, 2):
		# Выводим первое подходящее значение S и выходим из цикла. 
		print(i)
		break