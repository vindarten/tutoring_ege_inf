# https://inf-ege.sdamgia.ru/problem?id=36021

import itertools

count = 0
for w in itertools.product('ВИШНЯ', repeat=6):
	if w.count('В') <= 1 and w[0] != 'Ш' and w[-1] != 'И' and w[-1] != 'Я':
		count += 1
print(count)