// 16. 3Sum Closest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
	int twosumClosest(int *nums, int size, int target) {
		int left = 0;
		int right = size - 1;
		unsigned int best_gap = (-1);
		int best;

		while (left < right) {
			int lv = nums[left];
			int rv = nums[right];
			int sum = lv + rv;
			int gap = target - sum;
			gap = abs(gap);

			if ((unsigned int)gap < best_gap) {
				best_gap = gap;
				best = sum;
			}

			if (0 == best_gap) {
				break;
			}
			if (sum < target) {
				++left;
			}
			else if (sum > target) {
				--right;
			}
		}

		return best;
	}

	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) {
			return -1;
		}

		sort(nums.begin(), nums.end());
		int best = nums[0] + nums[1] + nums[2];
		int best_gap = abs(target - best);

		for (unsigned int i = nums.size() - 1; i >= 2; --i) {
			if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
				continue;
			}

			int sum = twosumClosest(&nums[0], i, target-nums[i])+nums[i];
			int gap = sum - target;
			gap = abs(gap);
			
			if (gap < best_gap) {
				best_gap = gap;
				best = sum;
			}

			if (0 == best_gap) {
				break;
			}
		}

		return best;
		
	}
};

static void test_func(vector<int> &v, int target)
{
	Solution s;
	int ret = s.threeSumClosest(v, target);

	cout << "(";
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << ",";
	}
	cout << ") target " << target;
	cout << " near " << ret << endl;
}

int main()
{
	vector<int> v = { -1, 2, 1, - 4 };
	test_func(v, 1);

    return 0;
}

