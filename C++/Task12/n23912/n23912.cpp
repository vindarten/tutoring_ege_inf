// https://inf-ege.sdamgia.ru/problem?id=23912

#include <iostream>

using namespace std;

int main()
{
	string s = string(1, '>') + string(10, '1') + string(20, '2') + string(30, '3');
	while (s.find(">1") != string::npos
		|| s.find(">2") != string::npos
		|| s.find(">3") != string::npos)
	{
		size_t pos = s.find(">1");
		if (pos != string::npos)
		{
			s.replace(pos, 2, "22>");
		}
		pos = s.find(">2");
		if (pos != string::npos)
		{
			s.replace(pos, 2, "2>");
		}
		pos = s.find(">3");
		if (pos != string::npos)
		{
			s.replace(pos, 2, "1>");
		}
	}
	long long c = 
		count(s.begin(), s.end(), '1') +
		count(s.begin(), s.end(), '2') * 2 +
		count(s.begin(), s.end(), '3') * 3;
	std::cout << c << std::endl;
	return 0;
}