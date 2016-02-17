// 5-Longest Palindromic Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

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

		std::stringstream tmp;
		tmp << '$';
		for (auto it = s.begin(); it != s.end(); ++it) {
			tmp << '#';
			tmp << *it;
		}
		tmp << '#';


		std::string ss = tmp.str();
		std::vector<int> p(ss.size(), 1);

		int mx = 0;
		int max = 1;
		int i;
		int id;
		int middle = 0;

		len = ss.size();
		for (i = 1; i < len; ++i) {
			if (mx > i) {
				p[i] = std::min(p[2 * id - i], mx - i);
			}
			else {
				p[i] = 1;
			}

			while (ss[i - p[i]] == ss[i + p[i]]) {
				p[i]++;
			}

			if (p[i] + i > mx) {
				mx = p[i] + i;
				id = i;				
			}

			if (p[i] > max) {
				max = p[i];
				if (ss[i] == '#') {
					middle = i / 2;
				}
				else {
					middle = i / 2 - 1;
				}
			}
		}
		max--;
		
		string max_str;
		max_str.reserve(max + 1);
		max_str.append(s, middle - max / 2, max);

		return max_str;
	}
};


class BruteSolution {
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

		max_str.reserve(max + 1);
		max_str.append(s, middle - max/2, max);

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
	test_func("ccd");
	test_func("abccba");
	test_func("eabadddd");
	test_func("eddabcacba");
    return 0;
}

