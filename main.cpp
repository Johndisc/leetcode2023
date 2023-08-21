#include <iostream>
#include "global.h"

#include "n10.h"
#include "sort.h"

int main() {
    Solution solution;
    vector<int> asd{-1, 3, -9, 6, 3, -2, 10};
    vector<vector<int>> qwe{{1,2,3},{4,5,6},{7,8,9}};
    string string1 = "abc3[cd]xyz";
//    auto res = solution.isMatch("aaa", "ab*a*c*a");
//    cout << res << endl;
//    for (auto item: res)
//        cout << item << " ";
//    for (auto item: res) {
//        for (auto j: item) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//    quickSort(asd, 0, asd.size() - 1);
    heap_sort(asd);
    for (int i: asd) {
        printf("%d ", i);
    }
    return 0;
}
