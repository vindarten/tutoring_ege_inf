// https://inf.reshuege.ru/problem?id=15787

#include <iostream>

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
					bool f = ((x <= y) && (y <= w)) || (z == (x || y));
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
