// 283. Move Zeroes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		unsigned int i = 0, j = 1;

		for (; i < nums.size(); ++i) {
			if (nums[i] == 0) {
				if (j <= i) {
					j = i + 1;
				}
				for (; j < nums.size(); ++j) {
					if (nums[j]) {
						break;
					}
				}

				if (j == nums.size()) {
					break;
				}
				
				swap(nums[i], nums[j]);
			}
		}
	}
};

int main()
{
	vector<int> v = { 0, 1, 0, 3, 12 };
	Solution s;
	s.moveZeroes(v);

	v = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
	s.moveZeroes(v);

    return 0;
}

