// 7.Reverse Integer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int flag = 1;
		int ret = 0;
		int m;
		long long long_ret = 0;

		if (x < 0) {
			flag = -1;
			x = -x;
			if (x < 0) {
				return 0;
			}
		}

		do {
			long_ret = (long long )ret * 10;
			ret = long_ret;
			if (ret < long_ret) {
				return 0;
			}

			m = x % 10;
			x = x / 10;
			ret += m;
		} while (x > 0);


		return flag*ret;
	}
};

static void test_func(int x)
{
	Solution s;
	int ret = s.reverse(x);

	cout << x << "->" << ret << endl;
}

int main()
{
	test_func(0);
	test_func(123);
	test_func(-123);
	test_func(2147483648);
	test_func(1534236469);
	test_func(-2147483412);

    return 0;
}

