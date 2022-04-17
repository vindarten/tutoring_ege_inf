// https://inf-ege.sdamgia.ru/problem?id=9365

#include <iostream>

using namespace std;

int main()
{
	string s(68, '8');
	while (s.find("222") != string::npos || s.find("888") != string::npos)
	{
		size_t pos = s.find("222");
		if (pos != string::npos)
		{
			s.replace(pos, 3, "8");
		}
		else
		{
			pos = s.find("888");
			s.replace(pos, 3, "2");
		}
	}
	std::cout << s << std::endl;
	return 0;
}