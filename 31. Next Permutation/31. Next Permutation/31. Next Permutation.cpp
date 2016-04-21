// 31. Next Permutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) {
			return;
		}

		int left, right;
		uint32_t size = nums.size();
		for (left = size - 1; left > 0; --left) {
			if (nums[left - 1] < nums[left]) {
				break;
			}
		}

		if (left > 0) {
			// Find left;
			--left;
			right = size - 1;
			while (nums[right] <= nums[left]) {
				--right;
			}
			swap(nums[left], nums[right]);
			sort(&nums[0] + left + 1, &nums[0] + size);
		}
		else {
			// Reset
			for (uint32_t i = 0; i < nums.size() / 2; ++i) {
				swap(nums[i], nums[nums.size() - i - 1]);
			}
		}
	}
};

static void test_func(vector<int> &nums, vector<int> &expect)
{
	Solution s;
	
	cout << "The next permutation of ";
	for (uint32_t i = 0; i < nums.size(); ++i) {
		cout << nums[i] << ", ";
	}
	cout << "is ";
	s.nextPermutation(nums);
	for (uint32_t i = 0; i < nums.size(); ++i) {
		cout << nums[i] << ", ";
	}
	if (nums != expect) {
		cout << "Not expected!!!";
	}
	cout << endl;
}


int main()
{
	vector<int> nums;
	vector<int> expect;

	nums = { 4,2,0,2,3,2,0 };
	expect = { 4,2,0,3,0,2,2 };
	test_func(nums, expect);

	nums = {};
	expect = {};
	test_func(nums, expect);

	nums = { 1 };
	expect = { 1 };
	test_func(nums, expect);

	nums = { 1,2 };
	expect = { 2, 1 };
	test_func(nums, expect);

	nums = { 1,2,3 };
	expect = { 1,3,2 };
	test_func(nums, expect);

	nums = { 1,3,2 };
	expect = { 2, 1, 3 };
	test_func(nums, expect);

	nums = { 3, 1, 2 };
	expect = { 3, 2, 1 };
	test_func(nums, expect);

	nums = { 3, 2, 1 };
	expect = { 1, 2, 3 };
	test_func(nums, expect);

	nums = { 1, 1, 2 };
	expect = { 1, 2, 1 };
	test_func(nums, expect);


    return 0;
}

