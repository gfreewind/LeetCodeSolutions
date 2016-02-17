// 5-Longest Palindromic Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();

		if (len == 0) {
			return "";
		}

		if (len == 1) {
			return s;
		}

		int max = 0;
		string max_str;
		bool is_odd = false;
		int middle = 0;

		for (int i = 0; i < len; ++i) {
			int j;
			int c;

			//odd case
			c = 1;
			for (j = 0; i - j - 1 >= 0 && i + j + 1 < len; ++j) {
				if (s[i - j - 1] != s[i + j + 1]) {
					break;
				}
				c = 1 + 2*(j + 1);
			}

			if (c > max) {
				is_odd = true;
				max = c;
				middle = i;
			}

			//even case
			c = 0;
			for (j = 0; i - j >= 0 && i + j + 1 < len; ++j) {
				if (s[i - j] != s[i + j + 1]) {
					break;
				}
				c = 2*(j + 1);
			}
			if (c > max) {
				is_odd = false;
				max = c;
				middle = i+1;
			}
		}

		int half = max / 2;

		if (is_odd) {
			max_str.append(s, middle - half, half + 1);
			max_str.append(s, middle + 1, half);
		}
		else {
			max_str.append(s, middle - half, max);
		}

		return max_str;
	}
};

static void test_func(string str)
{
	Solution s;
	string max = s.longestPalindrome(str);

	cout << str << ": " << max << endl;
}

int main()
{
	test_func("");
	test_func("a");
	test_func("aba");
	test_func("abcba");
	test_func("aa");
	test_func("abccba");
	test_func("eabadddd");
	test_func("eddabcacba");
    return 0;
}

