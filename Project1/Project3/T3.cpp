#include <iostream>
#include <map>

using namespace std;

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		map<char, map<int, int>> map;
//		string tempstr = "";
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (map.count(s[i]))
//			{
//				if (map[s[i]].size() == 1)
//					tempstr += s[i];
//				map[s[i]].insert({ map[s[i]].size() + 1, i });
//			}
//			else
//			{
//				map[s[i]] = { { 1,i } };
//			}
//		}
//
//		return 1;
//	}
//};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = -1, max = 0;
		map<int, int> map;
		for (int i = 0; i < s.size(); i++)
		{
			if (map.count(s[i]) && start < map[s[i]])
			{
				if (max < i - 1 - start)
					max = i - 1 - start;
				start = map[s[i]];
			}
			map[s[i]] = i;
		}
		if (max < s.size() - 1 - start && s.size() != 0)
			max = s.size() - 1 - start;
		return max;
	}
};

class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 1, max = 0;
		map<int, int> map;
		for (int i = 0; i < s.size(); i++)
		{
			if (start < map[s[i]])
			{
				if (max < i +2 - start)
					max = i +2 - start;
				start = map[s[i]];
			}
			map[s[i]] = i+1;
		}
		if (max < s.size() +1 - start && s.size() != 0)
			max = s.size() +1 - start;
		else if (s.size() == 1)
			max = 1;
		return max;
	}
};
//1234
int main()
{
	Solution2 s;

	string str = "ab";
	cout << endl;
	cout << endl << s.lengthOfLongestSubstring(str) << endl;
	cout << endl;
}