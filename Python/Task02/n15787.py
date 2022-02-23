# https://inf.reshuege.ru/problem?id=15787

print('x y z w f')
for x in [0, 1]:
    for y in [0, 1]:
        for z in [0, 1]:
            for w in [0, 1]:
                f = ((x <= y) and (y <= w)) or (z == (x or y)) 
                if not f:
                    print(x, y, z, w, int(f))
