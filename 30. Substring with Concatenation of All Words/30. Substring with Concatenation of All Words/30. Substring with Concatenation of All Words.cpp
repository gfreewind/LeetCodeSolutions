// 30. Substring with Concatenation of All Words.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		map<string, int> word_map;
		vector<int> ret;

		if (s.size() == 0) {
			return ret;
		}

		if (words.size() == 0) {
			return ret;
		}

		int per_word_len = words[0].size();
		int word_total_sum = 0;
		for (uint32_t i = 0; i < words.size(); ++i) {
			auto it = word_map.find(words[i]);
			if (it != word_map.end()) {
				word_total_sum += it->second;
			} 
			else {
				word_map[words[i]] = i + 1;
				word_total_sum += (i + 1);
			}
		}


		for (uint32_t i = 0; i < s.size(); ++i) {
			int sum = 0;
			int cnt = 0;
			for (uint32_t j = i; ; j += per_word_len) {
				if (j + per_word_len > s.size()) {
					i = j + per_word_len;
					break;
				}
				string tmp(&s[j], per_word_len);

				auto it = word_map.find(tmp);
				if (it != word_map.end()) {
					sum += it->second;
					cnt++;
					if (cnt == words.size()) {
						if (sum == word_total_sum) {
							ret.push_back(i);
						}
						break;
					}
				}
				else {
					break;
				}
			}
		}

		return ret;
	}
};

static void test_func(string s, vector<string> &words, vector<int> expected)
{
	Solution ss;
	vector<int> ret = ss.findSubstring(s, words);
	cout << "The results of " << s << " following: " << endl;
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << ", ";
	}
	if (ret != expected) {
		cerr << "Wrong results!!!" << endl;
	}
	cout << endl;
}


int main()
{
	string s = "barfoothefoobarman";
	vector<string> words = { "foo", "bar" };
	vector<int> expect = {0, 9};

	test_func(s, words, expect);

	s = "abcbdefghiabcbde";
	words = { "bcb","def","abc","bde","ghi" };
	expect = { 1 };
	test_func(s, words, expect);

	s = "wordgoodgoodgoodbestword";
	words = { "word","good","best","good" };
	expect = {8};
	test_func(s, words, expect);

	s = "aaaaaaaa";
	words = {"aa", "aa", "aa"};
	expect = { 0,1,2 };
	test_func(s, words, expect);

    return 0;
}

