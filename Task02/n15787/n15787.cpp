// https://inf-ege.sdamgia.ru/problem?id=15787e

#include <iostream>

bool imp(bool x, bool y)
{
    return !x || y;
}

int main()
{
    std::cout << "x y z w f" << std::endl;
    for (bool x : { false, true })
    {
        for (bool y : { false, true })
        {
            for (bool z : { false, true })
            {
                for (bool w : { false, true })
                {
                    bool f = (imp(x, y) && imp(y, w)) || (z == (x || y));
                    if (f == false)
                    {
                        std::cout << x << " " << y << " " << z << " " << w << " " << f << std::endl;
                    }
                }
            }
        }
    }
    return 0;
}


