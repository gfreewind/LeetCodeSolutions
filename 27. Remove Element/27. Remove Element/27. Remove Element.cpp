// 27. Remove Element.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0) {
			return 0;
		}

		int move_pos = -1;
		int len = 0;
		for (uint32_t i = 0; i < nums.size(); ++i) {
			if (nums[i] == val) {
				if (-1 == move_pos) {
					move_pos = i;
				}
			}
			else {
				len++;
				if (-1 != move_pos) {
					swap(nums[i], nums[move_pos]);
					++move_pos;
				}
			}
		}

		return len;
	}
};

static void test_func(vector<int> nums, int val)
{
	cout << "Orig: ";
	for (uint32_t i = 0; i < nums.size(); ++i) {
		cout << nums[i] << ", ";
	}
	cout << endl;

	Solution s;
	int len = s.removeElement(nums, val);
	cout << "After remove " << val << ": ";
	for (int i = 0; i < len; ++i) {
		cout << nums[i] << ", ";
	}
	cout << endl;
}

int main()
{
	vector<int> v;
	
	v = {};
	test_func(v, 3);

	v = { 1 };
	test_func(v, 1);

	v = { 3,2,2,3 };
	test_func(v, 3);

	v = { 1,2,3, };
	test_func(v, 5);

	v = { 1,1,1,1,1 };
	test_func(v, 1);

	v = { 1,1,1,2 };
	test_func(v, 1);

	v = { 1, 2,2,2, };
	test_func(v, 2);

    return 0;
}

