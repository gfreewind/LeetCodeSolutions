// 10. Regular Expression Matching.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
	bool __isMatchNormal(const char *s, int slen, const char *p, int plen)
	{
		if (s[0] == p[0]) {
			return __isMatch(s + 1, slen - 1, p + 1, plen - 1);
		}
		return false;
	}

	bool __isMatchDot(const char *s, int slen, const char *p, int plen)
	{
		return __isMatch(s + 1, slen - 1, p + 1, plen - 1);
	}

	bool __isMatchStar(const char *s, int slen, const char *p, int plen)
	{
		// skip * directly.
		if (__isMatch(s, slen, p + 1, plen - 1)) {
			return true;
		}

		if (0 == slen) {
			return false;
		}

		if ('.' == p[-1]) {
			return __isMatchStar(s + 1, slen - 1, p, plen);
		}
		else if (s[0] == p[-1]) {
			return __isMatchStar(s + 1, slen - 1, p, plen);
		}
		else {
			return false;
		}
	}

	bool __isMatch(const char *s, int slen, const char *p, int plen)
	{
		if (0 == plen && 0 == slen) {
			return true;
		}
		else if (0 == slen) {
			// Skip the pattern *
			if ('*' == p[0]) {
				return __isMatch(s, slen, p + 1, plen - 1);
			}
			// Skip cur and the pattern *
			else if ('*' == p[1]) {
				return __isMatch(s, slen, p + 2, plen - 2);
			}
			return false;
		}
		else if (0 == plen) {
			return false;
		}

		if ('*' == p[0]) {
			return __isMatchStar(s, slen, p, plen);
		}
		else if ('.' == p[0]) {
			if (__isMatchDot(s, slen, p, plen)) {
				return true;
			}
			// skip cur char and pattern *
			if ('*' == p[1]) {
				return __isMatch(s, slen, p + 2, plen - 2);
			}
			return false;
		}
		else {
			if (__isMatchNormal(s, slen, p, plen)) {
				return true;
			}

			// skip cur char and pattern *
			if ('*' == p[1]) {
				return __isMatch(s, slen, p + 2, plen - 2);
			}
			return false;
		}

	}
public:
	bool isMatch(string s, string p) {
		return __isMatch(s.c_str(), s.size(), p.c_str(), p.size());
	}
};

static void test_func(string ss, string p, bool expect_match)
{
	Solution s;
	bool ret = s.isMatch(ss, p);

	if (ret) {
		cout << ss << " matchs " << p;
		if (!expect_match) {
			cout << ". Not expected!!!";
		}
		cout << endl;
	}
	else {
		cout << ss << " fail to match " << p;
		if (expect_match) {
			cout << ". Not expected!!!";
		}
		cout << endl;
	}
}

int main()
{
	test_func("ab", ".*..", true);
	test_func("a", "ab*", true);
	test_func("", "", true);
	test_func("aab", "c*a*b", true);
	test_func("ab", ".*c", false);
	test_func("aa", "a", false);
	test_func("aa", "aa", true);
	test_func("aaa", "aa", false);
	test_func("aa", "a*", true);
	test_func("aa", ".*", true);
	test_func("ab", ".*", true);
	
    return 0;
}

