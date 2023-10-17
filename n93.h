//
// Created by 蒋子涵 on 2023/9/21.
//

#ifndef LEETCODE2023_N93_H
#define LEETCODE2023_N93_H
#include "global.h"

class Solution {
public:
	vector<string> res;

	bool check(const string& s) {
		if (s.size() > 3)
			return false;
		return stoi(s) <= 255;
	}

	void dfs(string &s, int pos, int cnt) {
		if (cnt == 3) {
			if (s[pos] == '0' && pos != s.size() - 1)
				return;
			if (check(s.substr(pos)))
				res.push_back(s);
			return;
		}
		if (s[pos] == '0') {
			if (pos == s.size() - 1)
				return;
			s.insert(pos + 1, 1, '.');
			dfs(s, pos + 2, cnt + 1);
			s.erase(pos + 1, 1);
			return;
		}
		int i = 1;
		while (pos + i < s.size()) {
			if (check(s.substr(pos, i))){
				s.insert(pos + i, 1, '.');
				dfs(s, pos + i + 1, cnt + 1);
				s.erase(pos + i, 1);
			}
			else
				break;
			i++;
		}
	}

	vector<string> restoreIpAddresses(string s) {
		dfs(s, 0, 0);
		return res;
	}
};
#endif //LEETCODE2023_N93_H
