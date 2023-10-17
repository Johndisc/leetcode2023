//
// Created by 蒋子涵 on 2023/9/4.
//

#ifndef LEETCODE2023_N75_H
#define LEETCODE2023_N75_H
#include "global.h"

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < nums.size() && nums[left] == 0)
			left++;
		while (right >= 0 && nums[right] == 2)
			right--;
		int pos = left;
		while (pos <= right) {
			if (nums[pos] == 2) {
				swap(nums[pos], nums[right]);
				while (right >= 0 && nums[right] == 2)
					right--;
			}
			else if (nums[pos] == 1) {
				pos++;
			}
			else {
				swap(nums[pos], nums[left]);
				pos++;
				left++;
			}
		}
	}
};
#endif //LEETCODE2023_N75_H
