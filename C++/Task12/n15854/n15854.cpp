// https://inf-ege.sdamgia.ru/problem?id=15854

#include <iostream>

using namespace std;

int main()
{
	string s = string(1, '1') + string(80, '0');
	while (s.find("10") != string::npos || s.find("1") != string::npos)
	{
		size_t pos = s.find("10");
		if (pos != string::npos)
		{
			s.replace(pos, 2, "001");
		}
		else
		{
			pos = s.find("1");
			if (pos != string::npos)
			{
				s.replace(pos, 1, "000");
			}
		}
	}
	std::cout << count(s.begin(), s.end(), '0') << std::endl;
	return 0;
}