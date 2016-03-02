// 11. Container With Most Water.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int max = 0;
		int left = 0;
		int right = height.size() - 1;
		int cur;

		while (left < right) {
			int x = right - left;
			int y;
			if (height[left] < height[right]) {
				y = height[left];
				left++;
			}
			else {
				y = height[right];
				right--;
			}
			cur = x*y;
			if (cur > max) {
				max = cur;
			}
		}

		return max;
	}
};

static void test_func(vector<int>& height)
{
	Solution s;
	int max = s.maxArea(height);

	cout << "The most water of ";
	for (auto it = height.begin(); it != height.end(); ++it) {
		cout << *it << " ";
	}
	cout << "is " << max << endl;
}

int main()
{
	vector<int> v;
	test_func(v);

	v = { 1, 2, 3, 4, 5 };
	test_func(v);

	v = { 5 };
	test_func(v);

	v = { 5, 5, 6, 3, 7,4 };
	test_func(v);


    return 0;
}

