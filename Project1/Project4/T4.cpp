#include <iostream>
#include <vector> 
#include <map> 

using namespace std;

class Solution {
public:
	map<int, int> map;
	int total = 0, count = 0;
	double ans = 0;
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
		//for (vector<int>::iterator i = nums1.begin(); i != nums1.end(); i++)
		//{
		//	map[*i] += 1;
		//	total++;
		//}

		//for (vector<int>::iterator i = nums2.begin(); i != nums2.end(); i++)
		//{
		//	map[*i] += 1;
		//	total++;
		//}

		//要NEW一個iterator要花時間跟空間
		//所以NEW INT比較簡單，而且是用O(1)直接取值
		for (int i = 0; i < nums1.size(); i++)
		{
			map[nums1[i]] += 1;
			total++;
		}

		for (int i = 0; i < nums2.size(); i++)
		{
			map[nums2[i]] += 1;
			total++;
		}

		//跑不出無條件進位
		//ans = ceil(total / 2);
		ans = total / 2;
		if (total % 2 == 1)
			ans ++;
		for (std::map<int, int>::iterator i = map.begin(); i != map.end(); i++)
		{
			for (int j = 0; j < (*i).second; j++)
			{
				count++;
				if (count == ans)
				{
					if (total % 2 == 0)
					{
						ans = (*i).first;
						if (j+1 == (*i).second)
						{
							i++;
							ans = (ans + (*i).first) / 2;
						}
					}
					else
					{
						ans = (*i).first;
					}
					return ans;
				}
			}
		}
		return 0;
	}
};


int main()
{
	Solution s1;
	vector<int> v1({ 5,1,2 });
	vector<int> v2({  });

	cout << endl;
	cout << endl << s1.findMedianSortedArrays(v1, v2) << endl;
	cout << endl;
}