// https://inf-ege.sdamgia.ru/problem?id=18495

#include <iostream>

using namespace std;

int main()
{
	string s = string(40, '1') + string(40, '2');
	while (s.find("111") != string::npos)
	{
		size_t pos = s.find("111");
		s.replace(pos, 3, "2");
		pos = s.find("222");
		s.replace(pos, 3, "1");
	}
	std::cout << s << std::endl;
	return 0;
}