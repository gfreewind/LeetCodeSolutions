// 15. 3Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define _SCL_SECURE_NO_WARNINGS

class Solution {
public:
	vector<vector<int>> twoSum(int *nums, int size, int value) {
		int left = 0;
		int right = size - 1;
		vector<vector<int>> ret;

		while (left < right) {
			int lv = nums[left];
			int rv = nums[right];
			int sum = lv + rv;

			if (lv > value && lv >= 0) {
				break;
			}

			if (sum > value) {
				right--;
			}
			else if (sum < value) {
				left++;
			}
			else {
				vector<int> v = { lv, rv };

				right--;
				left++;

				/* Avoid add duplicate ones */
				if (ret.size() > 0 && ret[ret.size()-1] == v) {
					continue;
				}

				ret.push_back(v);
			}
		}

		return ret;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		
		if (nums.size() < 3) {
			return ret;
		}

		sort(nums.begin(), nums.end());

		for (unsigned int i = nums.size() - 1; i >= 2; --i) {
			vector<vector<int>> two_sums;

			/* avoid duplicate ones */
			if (i < nums.size() - 1 && nums[i] == nums[i + 1]){
				continue;
			}

			two_sums = twoSum(&nums[0], i, -nums[i]);
			if (two_sums.size()) {
				for (auto it = two_sums.begin(); it != two_sums.end(); ++it) {
					it->push_back(nums[i]);
					ret.push_back(*it);
				}

			}
		}

		return ret;

	}
};

static void test_func(vector<int> v)
{
	Solution s;
	vector<vector<int>> ret;

	ret = s.threeSum(v);
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << ": " << endl;

	for (auto it = ret.begin(); it != ret.end(); ++it) {
		cout << "(";
		for (auto e = it->begin(); e != it->end(); ++e) {
			cout << *e << ", ";
		}
		cout << "), ";
	}
	cout << endl;
}

int main()
{
	vector<int> v = { -1, 0, 1, 2, -1, -4 };

	test_func(v);

	v = { 0, 0, 0 };
	test_func(v);

	v = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
	test_func(v);

    return 0;
}

