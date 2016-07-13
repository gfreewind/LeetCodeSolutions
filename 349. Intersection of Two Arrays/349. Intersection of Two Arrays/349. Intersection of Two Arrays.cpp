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
			for (; j != nums2.end();) {
				if (*i == *j) {
					int c = *i;
					ret.push_back(c);

					while (i != nums1.end()) {
						if (*i != c) {
							break;
						}
						++i;
					}
					while (j != nums2.end()) {
						if (*j != c) {
							break;
						}
						++j;
					}
					goto out;
				}
				else if (*i > *j) {
					++j;
				}
				else {
					++i;
				}
			}

out:
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

