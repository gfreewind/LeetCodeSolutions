// 33. Search in Rotated Sorted Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return -1;
		}

		int left = 0;
		int right = nums.size() - 1;
		int middle;

		do {
			middle = (left + right) / 2;
			if (nums[middle] == target) {
				return middle;
			}
			else {
				if (nums[middle] < nums[right]) {
					// [middle,right] is by order
					if (target > nums[middle] && target <= nums[right]) {
						left = middle + 1;
					}
					else {
						right = right - 1;
					}
				}
				else {
					// [left, middle] is by order
					if (target < nums[middle] && target >= nums[left]) {
						right = middle - 1;
					}
					else {
						left = left + 1;
					}
				}
			}
		} while (left <= right);

		return -1;
	}
};

static void test_func(vector<int> &nums, int target, int expect)
{
	Solution s;
	int ret = s.search(nums, target);
	cout << "Nums(";
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << ", ";
	}
	cout << ") has target " << target << " at " << ret;
	if (ret != expect) {
		cout << ", not expected " << expect;
	}
	cout << endl;
}

int main()
{
	vector<int> v = { 4, 5, 6, 7, 0, 1, 2 };

	test_func(v, 4, 0);
	test_func(v, 5, 1);
	test_func(v, 6, 2);
	test_func(v, 7, 3);
	test_func(v, 0, 4);
	test_func(v, 1, 5);
	test_func(v, 2, 6);
	test_func(v, 8, -1);

	v = { 7, 0, 1, 2, 4, 5, 6 };
	test_func(v, 4, 4);
	test_func(v, 5, 5);
	test_func(v, 6, 6);
	test_func(v, 7, 0);
	test_func(v, 0, 1);
	test_func(v, 1, 2);
	test_func(v, 2, 3);
	test_func(v, 8, -1);


    return 0;
}

