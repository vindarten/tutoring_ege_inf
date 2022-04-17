// https://inf-ege.sdamgia.ru/problem?id=10415

#include <iostream>

using namespace std;

int main()
{
	string s = string(99, '8') + string(1, '1');
	while (s.find("133") != string::npos || s.find("881") != string::npos)
	{
		size_t pos = s.find("133");
		if (pos != string::npos)
		{
			s.replace(pos, 3, "81");
		}
		else
		{
			pos = s.find("881");
			s.replace(pos, 3, "13");
		}
	}
	std::cout << s << std::endl;
	return 0;
}