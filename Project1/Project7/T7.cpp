#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int ansint = 0, temp = x;
		double ans = 0;
		if (temp < -pow(2, 31)+1)
			return 0;
		else if (temp < 0)
		{
			temp = -temp;
		}
		while (temp > 0)
		{
			if ((ans * 10 + temp % 10) > pow(2, 31) - 1 || (ans * 10 + temp % 10) < -pow(2, 31))
				return 0;
			ans = ans * 10 + temp % 10;
			temp = temp / 10;
		}
		if (x < 0)
		{
			ans = -ans;
		}
		ansint = ans;
		return ansint;
	}
};


//int上下限太多了，改用STRING反轉比較快
//超過INT範圍就用STOI功能的例外去處理
class Solution2 {
public:
	int reverse(int x) {
		string s,s2;
		int ans;
		if (x < 0) {
			s = (to_string(x)).substr(1);
			s += '-';
		}
		else {
			s = to_string(x);
		}

		for (int i = 0; i < s.length(); i++)
			s2 += s[s.length()-i-1];

		try {
			ans = stoi(s2);
		}
		catch (...) 
		{
			return 0;
		}

		return ans;
	}
};

int main()
{

	Solution2 s1;

	cout << endl;
	cout << endl << s1.reverse(1534236469) << endl;
	cout << endl;
}
