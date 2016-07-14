// 349. Intersection of Two Arrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		auto i = nums1.begin();
		auto j = nums2.begin();

		for (; i != nums1.end();) {
			if (ret.size() && *i == ret[ret.size()-1]) {
				++i;
				continue;
			}

			for (; j != nums2.end();) {
				if (*i == *j) {
					ret.push_back(*i);
					++i;
					++j;
					break;
				}
				else if (*i > *j) {
					++j;
				}
				else {
					++i;
					break;
				}
			}

			if (j == nums2.end()) {
				break;
			}
		}

		return ret;
	}
};


int main()
{
	vector<int> v1 = {3,};
	vector<int> v2 = {7,2,1,3 };

	Solution s;
	vector<int> ret = s.intersection(v1, v2);

    return 0;
}

