
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> words;
	words.push_back("adsffgh");
	words.push_back("zxcvsdfgwert");
	words.push_back("qwerert");
	std::map<char, int> row_map;
	row_map.insert(make_pair('q',1));row_map.insert(make_pair('w', 1));row_map.insert(make_pair('e', 1));row_map.insert(make_pair('r', 1)); 
	row_map.insert(make_pair('t', 1)); row_map.insert(make_pair('y', 1)); row_map.insert(make_pair('u', 1)); row_map.insert(make_pair('i', 1));
	row_map.insert(make_pair('o', 1)); row_map.insert(make_pair('p', 1));
	row_map.insert(make_pair('a', 2)); row_map.insert(make_pair('s', 2)); row_map.insert(make_pair('d', 2)); row_map.insert(make_pair('f', 2));
	row_map.insert(make_pair('g', 2)); row_map.insert(make_pair('h', 2)); row_map.insert(make_pair('j', 2)); row_map.insert(make_pair('k', 2));
	row_map.insert(make_pair('l', 2));
	row_map.insert(make_pair('z', 3)); row_map.insert(make_pair('x', 3)); row_map.insert(make_pair('c', 3)); row_map.insert(make_pair('v', 3));
	row_map.insert(make_pair('b', 3)); row_map.insert(make_pair('n', 3)); row_map.insert(make_pair('m', 3));
	vector<string> diff_words;
	for (int i = 0; i < words.size(); ++i)
	{
		const char* str = words[i].c_str();
		int cur_row = 0;
		bool diff = false;
		for (int j = 0; j < words[i].size(); ++j)
		{
			char s = tolower(str[j]);
			auto it = row_map.find(s);
			if (it == row_map.end())
			{
				diff = true;
				break;
			}
			if (cur_row && cur_row != it->second)
			{
				diff = true;
				break;
			}
			cur_row = it->second;
			if (diff)
				break;
		}
		if (!diff)
			diff_words.push_back(words[i]);
	}
	return 0;
}