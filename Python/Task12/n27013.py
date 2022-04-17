# https://inf-ege.sdamgia.ru/problem?id=27013

import itertools

maxSum = 0
for letters in itertools.product('12', repeat = 14):
	if letters.count('1') == 10 and letters.count('2') == 4:
		s = ''.join(letters)
		while '11' in s:
			if '112' in s:
				s = s.replace('112', '6', 1)
			else:
				s = s.replace('11', '3', 1)
		sum = s.count('1') + s.count('2')*2 + s.count('3')*3 + s.count('6')*6
		maxSum = max(sum, maxSum)
print(maxSum)