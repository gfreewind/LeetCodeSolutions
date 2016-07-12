// 258. Add Digits.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	int addDigits(int num) {
		int ret;

	repeat:
		ret = 0;
		while (num > 9) {
			int r = num % 10;
			num /= 10;
			ret += r;
		}

		ret += num;

		if (ret > 9) {
			num = ret;
			goto repeat;
		}

		return ret;
	}
};

void test_func(int num, int expect)
{
	Solution s;
	int ret = s.addDigits(num);

	cout << num << "'s sum is " << ret;
	if (ret == expect) {
		cout << ", ok" << endl;
	}
	else {
		cout << ", failed" << endl;
	}
}


int main()
{
	test_func(0, 0);
	test_func(2, 2);

	test_func(12, 3);
	test_func(19, 1);

	test_func(123, 6);
	test_func(999, 9);
    return 0;
}

