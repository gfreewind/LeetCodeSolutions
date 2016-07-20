// 217. Contains Duplicate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		for (uint32_t i = 1; i < nums.size(); ++i) {
			if (nums[i] == nums[i - 1]) {
				return true;
			}
		}

		return false;
	}
};

int main()
{
    return 0;
}

