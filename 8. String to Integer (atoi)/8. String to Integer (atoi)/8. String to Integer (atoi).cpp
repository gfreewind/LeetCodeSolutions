// 8. String to Integer (atoi).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		bool neg = false;
		auto it = str.begin();
		long long long_ret = 0;
		int ret;

		while (*it == ' ') {
			++it;
			if (it == str.end()) {
				return 0;
			}
		}

		if (*it == '-') {
			neg = true;
			++it;
		}
		else if (*it == '+') {
			++it;
		}

		for (; it != str.end(); ++it) {
			if (('0' <= *it && *it <= '9')) {
				long_ret = long_ret * 10 + *it - '0';
				if (long_ret >= INT_MAX) {
					break;
				}
			}
			else {
				break;
			}
		}

		ret = long_ret;
		if (ret < long_ret) {
			if (neg) {
				return INT_MIN;
			}
			else {
				return INT_MAX;
			}
		}

		if (neg) {
			return -ret;
		}
		else {
			return ret;
		}
	}
};


static void test_func(string ss)
{
	Solution s;
	int ret = s.myAtoi(ss);

	cout << ss << "->" << ret << endl;
}

int main()
{
	cout << "INT_MAX" << INT_MAX << endl;
	int x = 2147483648;

	cout << "x is " << x << endl;

	test_func("0");
	test_func("-1");
	test_func("-123");
	test_func("9");
	test_func("456");
	test_func("2231234234321423423423432");
	test_func("-3432132431542134243");
	test_func("    010");
	test_func("  -0012a42");
	test_func("2147483647");
	test_func("-2147483648");
	test_func("2147483648");
    return 0;
}

