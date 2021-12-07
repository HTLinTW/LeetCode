#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

//正著寫和反轉過來寫的內容都一樣稱為迴文palindromic 
class Solution {
public:
	string longestPalindrome(string s) {
		int length = 1, tempHalfLength;
		string ans = "";
		//分成奇與偶數
		//從第二字元開始
		//如果右邊還沒檢查的長度低於目前最大長度的一半，就可以停了
		for (int i = 1; i < s.length() - (length + 1) / 2; i++)
		{
			tempHalfLength = 1;
			//迴文半徑最長不會超過檢查字元到兩邊的最短距離
			while (tempHalfLength < i + 1 && tempHalfLength <= s.length() - i)
			{
				if (s[i - tempHalfLength] == s[i + tempHalfLength])
				{
					tempHalfLength++;
				}
				else
				{
					break;
				}
			}
			//半徑超過距離或是兩邊不相同時
			//退回去一格就是要的迴文
			tempHalfLength--;
			if (length < tempHalfLength * 2 + 1)
			{
				length = tempHalfLength * 2 + 1;
				ans = s.substr(i - tempHalfLength, length);
			}
		}

		for (int i = 0; i < s.length() - (length - 1) / 2; i++)
		{
			tempHalfLength = 1;
			while (tempHalfLength <= i + 1 && tempHalfLength <= s.length() - i)
			{
				if (s[i - tempHalfLength + 1] == s[i + tempHalfLength])
				{
					tempHalfLength++;
				}
				else
				{
					break;
				}
			}
			tempHalfLength--;
			if (length < tempHalfLength * 2)
			{
				length = tempHalfLength * 2;
				ans = s.substr(i - tempHalfLength + 1, length);
			}
		}

		if (s.length() == 1 || length == 1)
			ans = s[0];

		return ans;
	}
};


//字的中間與外側補字元
//這樣就都會是基數
//但速度不會比較快....
//中間找迴文的次數變多了
class Solution2 {
public:
	string longestPalindrome(string s) {
		int length = 1, tempHalfLength;
		string ans = "", newstr = " ";

		for (int i = 0; i < s.length(); i++)
		{
			newstr += s[i];
			newstr += " ";
		}

		//只算基數
		//從第二字元開始
		//如果右邊還沒檢查的長度低於目前最大長度的一半，就可以停了
		for (int i = 2; i < newstr.length() - length; i++)
		{
			tempHalfLength = 1;
			//迴文半徑最長不會超過檢查字元到兩邊的最短距離
			while (tempHalfLength < i + 1 && tempHalfLength <= newstr.length() - i)
			{
				if (newstr[i - tempHalfLength] == newstr[i + tempHalfLength])
				{
					tempHalfLength++;
				}
				else
				{
					break;
				}
			}
			tempHalfLength--;
			if (length < tempHalfLength )
			{
				length = tempHalfLength ;
				ans = s.substr((i - tempHalfLength) / 2, length);
			}
		}


		if (s.length() == 1 || length == 1)
			ans = s[0];

		return ans;
	}
};


int main()
{
	Solution2 s1;
	string str = "bb";

	cout << endl;
	cout << endl << s1.longestPalindrome(str) << endl;
	cout << endl;
}