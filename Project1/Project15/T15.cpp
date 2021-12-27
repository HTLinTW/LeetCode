#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans = {};

		for (int i = 0; i < nums.size() - 2; i++)
		{
			for (int j = i + 1; j < nums.size() - 1; j++)
			{
				std::vector<int>::iterator it;
				it = std::find(nums.begin() + j, nums.end(), -nums[i] - nums[j]);
				if (it != nums.end())
				{

					ans.push_back({ nums[i],nums[j],*it });
				}
			}
		}

		return ans;
	}
};

//class Solution2 {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
//		vector<vector<int>> ans = {};
//		multiset<int> temp = {};
//		for (int i = 0; i < nums.size(); i++)
//			temp.insert(nums[i]);
//
//		for (std::multiset<int>::iterator i = temp.begin(); i != (temp.end() - 2); i++)
//		{
//			for (auto j = ++i; j != temp.end() - 1; j++)
//			{
//				//std::vector<int>::iterator it;
//				auto it = temp.find( -*i - *j);
//				if (it != temp.end())
//				{
//
//
//					ans.push_back({ *i,*j,*it });
//				}
//			}
//		}
//
//		return ans;
//	}
//};

class Solution3 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		multiset<int> settemp(nums.begin(), nums.end());
		vector<int> temp(settemp.begin(), settemp.end());

		for (int i = 0; i < temp.size() - 2; i++)
		{
			try
			{
				if (temp[i] == temp.at(i - 1))
					continue;
			}
			catch (exception &e)
			{
			}
			for (int j = i + 1; j < temp.size() - 1; j++)
			{
				if (temp[j] == temp[j - 1] && j != i + 1)
					continue;
				std::vector<int>::iterator it = std::find(temp.begin() + j + 1, temp.end(), -temp[i] - temp[j]);
				if (it != temp.end())
					ans.push_back({ temp[i],temp[j],*it });
			}
		}
		return ans;
	}
};

//分正負
class Solution4 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		multiset<int> p = {}, m = {};
		int temp1 = 0, temp2 = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0)
				m.insert(nums[i]);
			else
				p.insert(nums[i]);
		}

		if (p.size() == 0)
			return {};
		else if (p.count(0) > 2)
			ans.push_back({ 0,0,0 });

		for (auto i = m.begin(); i != m.end(); i++)
		{
			auto j = i;
			j++;
			temp2 = 0;
			for (; j != m.end(); j++)
			{
				if (p.count(-*i - *j) > 0 && temp1 != *i && temp2 != *j)
					ans.push_back({ *i,*j,-*i - *j });
				temp2 = *j;
			}
			temp1 = *i;
		}

		temp1 = -1;
		for (auto i = p.begin(); i != p.end(); i++)
		{
			auto j = i;
			j++;
			temp2 = -1;
			for (; j != p.end(); j++)
			{
				if (m.count(-*i - *j) > 0 && temp1 != *i && temp2 != *j)
					ans.push_back({ -*i - *j,*i,*j });
				temp2 = *j;
			}
			temp1 = *i;
		}


		return ans;
	}
};


//用map檢查
class Solution5 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		multiset<int> p = {}, m = {};
		unordered_map<int, int> mp = {}, mm = {};
		int temp1 = 0, temp2 = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0)
			{
				if (mm[nums[i]] < 3)
				{
					if (mm[nums[i]] == 0)
					{
						mm[nums[i]] = 1;
						m.insert(nums[i]);
					}
					else
					{
						mm[nums[i]] += 1;
						m.insert(nums[i]);
					}
				}
			}
			else
			{
				if (mp[nums[i]] < 3)
				{
					if (mp[nums[i]] == 0)
					{
						mp[nums[i]] = 1;
						p.insert(nums[i]);
					}
					else
					{
						mp[nums[i]] += 1;
						p.insert(nums[i]);
					}
				}
			}
		}

		if (p.size() == 0)
			return {};
		else if (p.count(0) > 2)
			ans.push_back({ 0,0,0 });

		for (auto i = m.begin(); i != m.end(); i++)
		{
			auto j = i;
			j++;
			temp2 = 0;
			for (; j != m.end(); j++)
			{
				if (p.count(-*i - *j) > 0 && temp1 != *i && temp2 != *j)
					ans.push_back({ *i,*j,-*i - *j });
				temp2 = *j;
			}
			temp1 = *i;
		}

		temp1 = -1;
		for (auto i = p.begin(); i != p.end(); i++)
		{
			auto j = i;
			j++;
			temp2 = -1;
			for (; j != p.end(); j++)
			{
				if (m.count(-*i - *j) > 0 && temp1 != *i && temp2 != *j)
					ans.push_back({ -*i - *j,*i,*j });
				temp2 = *j;
			}
			temp1 = *i;
		}


		return ans;
	}
};



//完全用map
class Solution6 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		map<int, int> mp = {}, mm = {};
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 1)
			{
				if (mm[nums[i]] < 3)
				{
					if (mm[nums[i]] == 0)
						mm[nums[i]] = 1;
					else
						mm[nums[i]] += 1;
				}
			}
			else
			{
				if (mp[nums[i]] < 3)
				{
					if (mp[nums[i]] == 0)
						mp[nums[i]] = 1;
					else
						mp[nums[i]] += 1;
				}
			}
		}

		if (mm.size() == 0)
			return {};

		for (auto i = mm.begin(); i != mm.end(); i++)
		{
			auto j = i;
			//一定要有()才能.出first
			if ((*i).second == 1)
				j++;
			for (; j != mm.end(); j++)
			{
				if (mp.count(-(*i).first - (*j).first) > 0)
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}

		if (mm[0] > 2)
			ans.push_back({ 0,0,0 });

		for (auto i = mp.begin(); i != mp.end(); i++)
		{
			auto j = i;
			if ((*i).second == 1)
				j++;
			for (; j != mp.end(); j++)
			{
				if (mm.count(-(*i).first - (*j).first) > 0)
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}
		return ans;
	}
};

//不用排序也可以
//所以改用unordered_map
//加上下限
class Solution7 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		unordered_map<int, int> mp = {}, mm = {};
		int imax = 0, imin = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 1)
			{
				if (mm[nums[i]] < 3)
				{
					mm[nums[i]] += 1;
					imin = min(imin, nums[i]);
				}
			}
			else
			{
				if (mp[nums[i]] < 3)
				{
					mp[nums[i]] += 1;
					imax = max(imax, nums[i]);
				}
			}
		}

		if (mm.size() == 0)
			return {};

		for (auto i = mm.begin(); i != mm.end(); i++)
		{
			if (imax < -(*i).first)
				continue;
			auto j = i;
			//一定要有()才能.出first
			if ((*i).second == 1)
				j++;
			for (; j != mm.end(); j++)
			{
				if (imax < -(*i).first - (*j).first)
					continue;
				if (mp.count(-(*i).first - (*j).first) > 0)
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}

		//要放在這邊，不然會因為使用mm[0]而產生{0,0}的資料
		if (mm[0] > 2)
			ans.push_back({ 0,0,0 });

		for (auto i = mp.begin(); i != mp.end(); i++)
		{
			if (-imin < (*i).first)
				continue;
			auto j = i;
			if ((*i).second == 1)
				j++;
			for (; j != mp.end(); j++)
			{
				if (-imin < (*i).first + (*j).first)
					continue;
				if (mm.count(-(*i).first - (*j).first) > 0)
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}
		return ans;
	}
};


//不分正負
class Solution8 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> myans = {};
		unordered_map<int, int> mymap = {};
		unordered_set<int> myset = {};
		int imax = 0, imin = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (mymap[nums[i]] < 3)
			{
				mymap[nums[i]] += 1;
				imin = min(imin, nums[i]);
				imax = max(imax, nums[i]);
			}
		}

		if (mymap[0] > 2)
			myans.push_back({ 0,0,0 });
		else if (mymap[0] == 0)
			mymap.erase(0);

		for (auto i = mymap.begin(); i != mymap.end(); i++)
		{
			if (imax < -(*i).first || -imin < (*i).first)
				continue;
			auto j = i;
			//一定要有()才能.出first
			//if ((*i).second == 1)
			j++;
			for (; j != mymap.end(); j++)
			{
				if (imax < -(*i).first - (*j).first || -imin < (*i).first + (*j).first)
					continue;
				if (myset.count((*j).first) > 0)
					continue;
				//error
				//auto k = std::find(j, map.end(), -(*i).first - (*j).first);
				//if (k == map.end())
				//	continue;
				//加個SKIP吧
				//一輪完之後將i的VALUE為0
				if ((-(*i).first - (*j).first) == (*i).first || (-(*i).first - (*j).first) == (*j).first)
				{
					if (mymap[(-(*i).first - (*j).first)] > 1)
					{
						myans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
						myset.insert((*j).first);
						myset.insert(-(*i).first - (*j).first);
					}
					continue;
				}
				if (mymap[(-(*i).first - (*j).first)] > 0)
				{
					myans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
					myset.insert((*j).first);
					myset.insert(-(*i).first - (*j).first);
				}
			}
			mymap[(*i).first] = 0;
			myset.clear();
		}
		return myans;
	}
};


int main()
{
	Solution8 s;
	vector<int> v = { 1,1,-2 };

	cout << endl;
	cout << endl << s.threeSum(v)[0][0] << endl;
	cout << endl;
}