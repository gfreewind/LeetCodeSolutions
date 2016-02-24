// 9. Palindrome Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}

		if (x < 10) {
			return true;
		}

		int div = 10;
		while (x / div >= 10) {
			div *= 10;
		}

		int left, right;
		while (1) {
			left = x / div;
			right = x % 10;

			if (left != right) {
				return false;
			}
			x = (x % div) / 10;
			div /= 100;

			if (div < 10) {
				break;
			}
		}

		return true;
	}
};

static void test_func(int x)
{
	Solution s;
	bool ret = s.isPalindrome(x);

	cout << x << " is " << ret << " palindrome" << endl;

}

int main()
{
	test_func(1000030001);
	test_func(0);
	test_func(-1);
	test_func(10);
	test_func(1874994781);
	test_func(1000021);
	test_func(121);
	test_func(1221);
	test_func(1231);
	test_func(12321);
    return 0;
}

