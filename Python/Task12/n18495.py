# https://inf-ege.sdamgia.ru/problem?id=18495

s = '1'*40 + '2'*40
while '111' in s:
	s = s.replace('111', '2', 1)
	s = s.replace('222', '1', 1)
print(s)