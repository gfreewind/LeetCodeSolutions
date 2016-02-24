// 9. Palindrome Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int bits = 1;
		unsigned long long max_moder = 10;
		int last_left = 0;

		if (x < 0) {
			return false;
		}

		if (x < 10) {
			return true;
		}

		while (x > max_moder) {
			++bits;
			max_moder *= 10;
		}

		max_moder /= 10;

		int left, right;
		while (1) {
			left = x / max_moder;
			left = left - last_left;
			right = x % 10;

			if (left != right) {
				return false;
			}
			last_left = (last_left + left)*10;

			x /= 10;
			max_moder /= 100;

			if (max_moder <= 0) {
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

