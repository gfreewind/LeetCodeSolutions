// 17. Letter Combinations of a Phone Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

struct CharStatus {
	const char cur_;
	const char next_;
	const bool promote_;
};
static const CharStatus char_maps[] = {
	{ '\0', '\0', true },
	{ ' ', ' ', true },
	{'a', 'b', false},
	{'b', 'c', false},
	{'c', 'a', true},
	{'d', 'e', false},
	{'e', 'f', false},
	{'f', 'd', true},
	{'g', 'h', false},
	{'h', 'i', false},
	{'i', 'g', true},
	{'j', 'k', false},
	{'k', 'l', false},
	{'l', 'j', true},
	{'m', 'n', false},
	{'n', 'o', false},
	{'o', 'm', true},
	{'p', 'q', false},
	{'q', 'r', false},
	{'r', 's', false},
	{'s', 'p', true},
	{'t', 'u', false},
	{'u', 'v', false},
	{'v', 't', true},
	{'w', 'x', false},
	{'x', 'y', false},
	{'y', 'z', false},
	{'z', 'w', true},
};

const vector<string> letter_maps_ = {
	" ",
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz",
};


class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		string str;

		if (digits.size() == 0) {
			return ret;
		}

		for (unsigned int i = 0; i < digits.size(); ++i) {
			int nr = digits[i] - '0';
			string letters = letter_maps_[nr];
			str.push_back(letters[0]);
		}

		do {
			ret.push_back(str);
		} while (get_next_promotion(str));

		return ret;
	}
private:

	bool get_next_char(char &c)
	{
		int left = 0;
		int right = sizeof(char_maps) / sizeof(char_maps[0])-1;

		while (left <= right) {
			int middle = (left + right) / 2;
			if (char_maps[middle].cur_ == c) {
				c = char_maps[middle].next_;
				return char_maps[middle].promote_;
			}
			else if (char_maps[middle].cur_ < c) {
				left=middle+1;
			}
			else {
				right=middle-1;
			}
		}
		assert(false);

		return true;
	}

	bool get_next_promotion(string& str)
	{
		bool promote;

		for (int i = str.size() - 1; i >= 0; --i) {
			promote = get_next_char(str[i]);
			if (promote) {
				if (i == 0) {
					return false;
				}
			}
			else {
				break;
			}
		}

		return true;
	}
};

static void test_func(string digits)
{
	Solution s;
	vector<string> ret = s.letterCombinations(digits);

	cout << digits << ": ";
	for (auto it = ret.begin(); it != ret.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl;
}


int main()
{
	string digits = "9";
	test_func(digits);

	digits = "";
	test_func(digits);

	digits = "23";
	test_func(digits);

    return 0;
}

