#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> merged;
		//������FUNCTION�AMERGE�P�Ƨ�
		std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(merged));

		int n = merged.size();
		if (merged.size() % 2 == 0)
			return (double)(merged[(n - 1) / 2] + merged[n / 2]) / 2;
		else
			return (double)(merged[(n - 1) / 2]);
	}
};





//�ӷ���nums1�P2���O�w�gSORT�L��....
//�ҥH�i�H���Υ�������
class Solution2 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>nums;
		int n1 = nums1.size();
		int n2 = nums2.size();
		int i = 0, j = 0;
		while (i < n1 && j < n2) {
			if (nums1[i] <= nums2[j]) {
				nums.push_back(nums1[i]);
				i++;
			}
			else {
				nums.push_back(nums2[j]);
				j++;
			}
		}
		while (i < n1) {
			nums.push_back(nums1[i]);
			i++;
		}
		while (j < n2) {
			nums.push_back(nums2[j]);
			j++;
		}
		double n = nums.size();
		int l = n / 2;
		if ((nums.size()) % 2 != 0)
		{
			return nums[l];
		}
		else {
			return double(nums[l] + nums[l - 1]) / 2;
		}
	}
};