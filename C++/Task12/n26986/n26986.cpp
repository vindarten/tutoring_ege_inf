// https://inf-ege.sdamgia.ru/problem?id=26986

#include <iostream>

using namespace std;

int main()
{
	string s = string(40, '7') + string(40, '9') + string(50, '4');
	while (s.find("49") != string::npos
		|| s.find("97") != string::npos
		|| s.find("47") != string::npos)
	{
		size_t pos = s.find("47");
		if (pos != string::npos)
		{
			s.replace(pos, 2, "74");
		}
		pos = s.find("97");
		if (pos != string::npos)
		{
			s.replace(pos, 2, "79");
		}
		pos = s.find("49");
		if (pos != string::npos)
		{
			s.replace(pos, 2, "94");
		}
	}
	std::cout << s[25 - 1] << s[71 - 1] << s[105 - 1] << std::endl;
	return 0;
}