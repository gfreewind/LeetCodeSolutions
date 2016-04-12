// 26. Remove Duplicates from Sorted Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}

		int cur = nums[0];
		int len = 1;
		int move_pos = -1;
		for (uint32_t i = 1; i < nums.size(); ++i) {
			if (nums[i] == cur) {
				if (move_pos == -1) {
					move_pos = i;
				}
			}
			else {
				len++;
				cur = nums[i];
				if (move_pos != -1) {
					swap(nums[move_pos], nums[i]);
					move_pos++;
				}
			}
		}

		return len;
	}
};

static void test_func(vector<int>& nums)
{
	Solution s;

	cout << "Orig: ";
	for (uint32_t i = 0; i < nums.size(); ++i) {
		cout << nums[i] << ", ";
	}
	cout << endl;

	int len = s.removeDuplicates(nums);
	cout << "After remove: ";
	for (int i = 0; i < len; ++i) {
		cout << nums[i] << ", ";
	}
	cout << endl;
}

int main()
{
	vector<int> v;

	v = { 1, 1, 2 };
	test_func(v);

	v = {};
	test_func(v);

	v = {1};
	test_func(v);

	v = { 1, 1, 2, 3, 3,4,5,6,7,8,8,8,8,8,9 };
	test_func(v);

	v = { 1, 2,2,3,3,3,3,3,3,3,3,3};
	test_func(v);

	v = { 1, 1, 1,1,1,1,1};
	test_func(v);


    return 0;
}

