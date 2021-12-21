#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> map = { {'I',1},{'V',5} ,{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		int ans = 0, temp = 0;

		//for (int i = s.length() - 1; i >= 0; i--)
		//不要用>=或<=，因為多一個=的判斷，速度會變慢
		for (int i = s.length() - 1; i > -1; i--)
		{
			if (temp > map[s[i]])
				ans -= map[s[i]];
			else
				ans += temp = map[s[i]];

		}

		return ans;
	}
};

//需要辨識的資料太少，所以用map不會比較快
class Solution2 {
public:
	int roman(char c)
	{
		switch (c)
		{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
	}

	int romanToInt(string s) {
		int ans = 0, temp = 0;
		for (int i = s.length() - 1; i > -1; i--)
		{
			if (temp > roman(s[i]))
				ans -= roman(s[i]);
			else
				ans += temp = roman(s[i]);
		}
		return ans;
	}
};

int main()
{
	Solution s;

	cout << endl;
	cout << endl << s.romanToInt("MCMXCIV") << endl;
	cout << endl;
}