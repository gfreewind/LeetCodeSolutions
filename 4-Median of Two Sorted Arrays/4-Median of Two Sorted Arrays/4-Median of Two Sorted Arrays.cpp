// 4-Median of Two Sorted Arrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
private:
	int find_kth_num(int *nums1, int size1, int *nums2, int size2, int k)
	{
		if (size1 > size2) {
			return find_kth_num(nums2, size2, nums1, size1, k);
		}

		if (0 == size1) {
			return nums2[k-1];
		}

		if (1 == k) {
			return min(nums1[0], nums2[0]);
		}

		int p1 = min(k / 2, size1);
		int p2 = k - p1;
		int n1 = nums1[p1-1];
		int n2 = nums2[p2-1];

		if (n1 < n2) {
			return find_kth_num(nums1 + p1, size1 - p1, nums2, size2, k - p1);
		}
		else if (n1 > n2) {
			return find_kth_num(nums1, size1, nums2 + p2, size2 - p2, k - p2);
		}
		else {
			return n1;
		}
	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total = nums1.size() + nums2.size();
		int middle = total / 2;

		if (total & 1) {
			return find_kth_num(nums1.data(), nums1.size(), nums2.data(), nums2.size(), middle+1);
		}
		else {
			int n1 = find_kth_num(nums1.data(), nums1.size(), nums2.data(), nums2.size(), middle);
			int n2 = find_kth_num(nums1.data(), nums1.size(), nums2.data(), nums2.size(), middle+1);
			return (double)(n1 + n2) / 2;
		}
	}
};

class MergeSolution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() == 0) {
			if (nums2.size() % 2) {
				return nums2[nums2.size() / 2];
			}
			else {
				int former = nums2[nums2.size() / 2 - 1];
				int latter = nums2[nums2.size() / 2];
				return (double)(former + latter) / 2;
			}
		}
		else if (nums2.size() == 0) {
			if (nums1.size() % 2) {
				return nums1[nums1.size() / 2];
			}
			else {
				int former = nums1[nums1.size() / 2 - 1];
				int latter = nums1[nums1.size() / 2];
				return (double)(former + latter) / 2;
			}
		}
		else {
			unsigned int total = nums1.size() + nums2.size();
			unsigned int nth = total / 2;
			unsigned int i, j, k;
			int n1;
			int n2;
			int v1;
			int v2;

			i = j = k = 0;
			for (i = 0; i <= nth; ++i) {
				if (j < nums1.size())
					n1 = nums1[j];
				if (k < nums2.size())
					n2 = nums2[k];

				if ((j < nums1.size() && n1 <= n2) || k >= nums2.size()) {
					++j;
					if (i == nth - 1) {
						v1 = n1;
					}
					else if (i == nth) {
						v2 = n1;
					}
				}
				else {
					++k;
					if (i == nth - 1) {
						v1 = n2;
					}
					else if (i == nth) {
						v2 = n2;
					}

				}
			}

			if (total % 2) {
				return v2;
			}
			else {
				return double(v1 + v2) / 2;
			}
		}
	}
};

static void test_func(vector<int> &v1, vector<int> &v2)
{
	Solution s;
	MergeSolution s2;
	double ret = s.findMedianSortedArrays(v1, v2);
	cout << "Result1 is " << ret << endl;
	ret = s2.findMedianSortedArrays(v1, v2);
	cout << "Result2 is " << ret << endl;
}

int main()
{
	vector<int> v1 = {};
	vector<int> v2 = { 1,2,3 };
	test_func(v1, v2);

	v1 = { 1,2 };
	v2 = {};
	test_func(v1, v2);

	v1 = { 1 };
	v2 = { 2, 3 };
	test_func(v1, v2);

	v1 = { 1,3,5 };
	v2 = { 2,4,6 };
	test_func(v1, v2);
	test_func(v2, v1);
	v1 = { 2,4,6,7 };
	v2 = { 1,3,5 };
	test_func(v1, v2);
	


    return 0;
}

