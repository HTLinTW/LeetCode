#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int  temp = x;
		long rex = 0;
		if (x < 0)
			return false;

		while (temp > 0)
		{
			rex = rex * 10 + temp % 10;
			temp = temp / 10;
		}

		if (rex == x)
			return true;
		return false;
	}
};


int main()
{
	Solution s1;

	cout << endl;
	cout << endl << s1.isPalindrome(123456789) << endl;
	cout << endl;
}