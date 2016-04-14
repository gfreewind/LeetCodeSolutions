// 29. Divide Two Integers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {

		if (0 == divisor) {
			return INT_MAX;
		} 

		bool negative = false;
		long long ldividend = dividend;
		long long ldivisor = divisor;

		if (ldividend >= 0) {
			if (ldivisor < 0) {
				negative = true;
				ldivisor = -ldivisor;
			}
		}
		else {
			ldividend = -ldividend;
			if (ldivisor > 0) {
				negative = true;
			}
			else {
				ldivisor = -ldivisor;
			}
		}

		long long lret = 0;
		if (ldivisor == 1) {
			lret = ldividend;
		}
		else {
			unsigned long long similar_divisor = ldivisor;
			unsigned long long similor_ret = 1;

			while (similar_divisor <= (unsigned long long)ldividend) {
				similar_divisor <<= 1;
				similor_ret <<= 1;
			}

			while (ldivisor <= ldividend) {
				similar_divisor >>= 1;
				similor_ret >>= 1;
				if (similar_divisor <= (unsigned long long)ldividend) {
					ldividend -= similar_divisor;
					lret += similor_ret;
				}
			}
		}

		int ret;
		if (lret > INT_MAX) {
			ret = INT_MAX;
			if (negative) {
				ret = INT_MIN;
			}
		}
		else {
			ret = lret;
			if (negative) {
				ret = -ret;
			}
		}

		return ret;
	}
};

static void test_func(int dividend, int divisor, int expect)
{
	Solution s;
	int ret = s.divide(dividend, divisor);

	cout << "Dividend: " << dividend << ", "
		<< "Divisor: " << divisor << ", "
		<< "Ret: " << ret << ", ";
	if (ret == expect) {
		cout << "Expected" << endl;
	}
	else {
		cout << "Not expected " << expect << endl;
	}
}

int main()
{
	test_func(0, 0, INT_MAX);
	test_func(1, 1, 1);
	test_func(5, 3, 5 / 3);
	test_func(100, 20, 100 / 20);
	test_func(5, 7, 5 / 7);
	test_func(-2, 5, -2 / 5);
	test_func(2147483647, 2, 2147483647 / 2);
	test_func(INT_MIN, 2, INT_MIN / 2);
	test_func(INT_MIN, -1, INT_MAX);
	test_func(INT_MIN, 1, INT_MIN);

    return 0;
}

