// 3-Longest Substring Without Repeating Chars.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int dup_index[256];

		for (int i = 0; i < 256; ++i) {
			dup_index[i] = -1;
		}

		int cur = 0;
		int max = 0;
		int restart = 0;
		for (auto it = s.begin(); it != s.end(); ++it) {
			if (dup_index[*it] >= restart) {
				if (cur > max) {
					max = cur;
				}

				cur = (it - s.begin())-dup_index[*it];
				restart = dup_index[*it] + 1;
				dup_index[*it] = it - s.begin();
			}
			else {
				dup_index[*it] = it - s.begin();
				++cur;
			}
		}

		if (cur > max) {
			max = cur;
		}

		return max;
	}
};

class BruteSolution {
public:
	int lengthOfLongestSubstring(string s) {
		int max = 0;

		for (auto it = s.begin(); it != s.end(); ++it) {
			bool filter[256] = { 0 };
			int ret = 0;

			filter[*it] = true;
			ret = 1;

			auto pos = it + 1;
			for (; pos != s.end(); ++pos) {
				if (filter[*pos]) {
					break;
				}
				filter[*pos] = true;
				++ret;
			}

			if (ret > max) {
				max = ret;
			}

		}

		return max;
	}
};


int main()
{
	Solution s;
	string t = "dvdf";
	int ret = s.lengthOfLongestSubstring(t);
	cout << t << ":" << ret << endl;

	t = "vqblqcb";
	ret = s.lengthOfLongestSubstring(t);
	cout << t << ":" << ret << endl;

	t = "pwwkew";
	ret = s.lengthOfLongestSubstring(t);
	cout << t << ":" << ret << endl;

	t = "uqinntq";
	ret = s.lengthOfLongestSubstring(t);
	cout << t << ":" << ret << endl;

	t = "au";
	ret = s.lengthOfLongestSubstring(t);
	cout << t << ":" << ret << endl;
	t = "a";
	ret = s.lengthOfLongestSubstring(t);
	cout << t << ":" << ret << endl;
	t = "";
	ret = s.lengthOfLongestSubstring(t);
	cout << t << ":" << ret << endl;

	t = "eeee";
	ret = s.lengthOfLongestSubstring(t);
	cout << t << ":" << ret << endl;

	t = "bacdefab";
	ret = s.lengthOfLongestSubstring(t);
	cout << t << ":" << ret << endl;

    return 0;
}

