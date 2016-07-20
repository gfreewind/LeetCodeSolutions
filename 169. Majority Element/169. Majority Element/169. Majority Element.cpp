// 169. Majority Element.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int nr = 0;
		int cnt = 0;

		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (cnt) {
				if (*it == nr) {
					cnt++;
				}
				else {
					cnt--;
				}
			}
			else {
				nr = *it;
				cnt = 1;
			}
		}

		return nr;
	}
};


int main()
{
	vector<int> v = { 1,1,2 };
	Solution s;
	int ret = s.majorityElement(v);

	v = { 1,2,1,3, 1,4, 1};
	ret = s.majorityElement(v);

	v = { 1, 1, 1, 2, 3 };
	ret = s.majorityElement(v);

	v = { 8, 8, 7, 7, 7 };
	ret = s.majorityElement(v);

	v = { 8,9,8,9,8 };
	ret = s.majorityElement(v);

    return 0;
}

