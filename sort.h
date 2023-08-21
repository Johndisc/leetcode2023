//
// Created by 蒋子涵 on 2023/8/9.
//

#ifndef LEETCODE2023_SORT_H
#define LEETCODE2023_SORT_H
#include "global.h"

void quickSort(vector<int> &nums, int s, int e) {
    if (s >= e)
        return;
    int i = s, j = e;
    int mid = nums[s];
    while (i < j) {
        while (j > i && nums[j] >= mid)
            j--;
        if (j == i)
            break;
        nums[i] = nums[j];
        while (i < j && nums[i] <= mid)
            i++;
        if (i == j)
            break;
        nums[j] = nums[i];
    }
    nums[i] = mid;
    quickSort(nums, s, i - 1);
    quickSort(nums, i + 1, e);
}

void adjust(vector<int> &nums, int n, int index) {
    int max_index = index;
    int left = 2 * index + 1;       // left child
    int right = 2 * index + 2;      // right child

    if (left < n && nums[left] > nums[max_index])
        max_index = left;
    if (right < n && nums[right] > nums[max_index])
        max_index = right;

    if (max_index != index) {
        swap(nums[max_index], nums[index]);
        adjust(nums, n, max_index);
    }
}

void heap_sort(vector<int> &nums) {
    // position of the last non-leaf node : (n-1)/2
    for (int i = (nums.size() - 1) / 2; i >= 0; i--) {
        adjust(nums, nums.size(), i);
    }

    for (int i = nums.size() - 1; i > 0; i--) {
        swap(nums[i], nums[0]);
        adjust(nums, i, 0);
    }
}

#endif //LEETCODE2023_SORT_H
