#include <iostream>
#include <map>
#include <algorithm>

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
		int start = -1, Max = 0;
		map<int, int> map;
		for (int i = 0; i < s.size(); i++)
		{
			if (map.count(s[i]) && start < map[s[i]])
			{
				if (Max < i - 1 - start)
					Max = i - 1 - start;
				start = map[s[i]];
			}
			map[s[i]] = i;
		}
		if (Max < s.size() - 1 - start && s.size() != 0)
			Max = s.size() - 1 - start;
		return Max;
	}
};

class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		int start = -1, Max = 0;
		map<int, int> map;
		for (int i = 0; i < s.size(); i++)
		{
			if (map.count(s[i]) && start < map[s[i]])
			{
				Max = max(Max, i - 1 - start);
				start = map[s[i]];
			}
			map[s[i]] = i;
		}
		if (s.size() != 0)
			Max = max(Max, (int)(s.size() - 1 - start));
		return Max;
	}
};

//���ϥ�Key Value����
//�t���٤����....
//�D�n�t�A�j�M�t��
//���Mmap�OO(logN)
//���j�M���ƭȪ��a�蹳�O��O(N)����[
//���j�M���ƭȬO�qstart�}�l��A�Ӥ��O���Y�A�ҥH�t�ק֤W�ܦh�AN��w�����d��p�ܦh
//�p�G�O�q0�}�l���ܡA���㪺O(N)�ɶ��N�|���t�F
class Solution2plus {
public:
	int lengthOfLongestSubstring(string s) {
		int start = -1, Max = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = start; j < i; j++)
			{
				if (j == -1)
					continue;
				if (s[i] == s[j] && start < j)
				{
					Max = max(Max, i - 1 - start);
					start = j ;
					break;
				}
			}
		}
		if (s.size() != 0)
			Max = max(Max, (int)(s.size() - 1 - start));
		return Max;
	}
};

//�޿�令F1��S2�A����VECTOR��map���ܳt�פW�٬O���t
class Solution3 {
public:
	int lengthOfLongestSubstring(string s) {
		int start = -1, Max = 0;
		map<int, int> map;
		for (int i = 0; i < s.size(); i++)
		{
			if (map.count(s[i]))
			{
				start = max(start, map[s[i]]);
			}
			Max = max(Max, i - start);
			map[s[i]] = i;
		}
		return Max;
	}
};



//1234

//int main()
//{
//	Solution2 s;
//
//	string str = "ab";
//	cout << endl;
//	cout << endl << s.lengthOfLongestSubstring(str) << endl;
//	cout << endl;
//}