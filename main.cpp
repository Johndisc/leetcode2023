#include <iostream>
#include "global.h"

#include "n394.h"


int main() {
    Solution solution;
    vector<int> asd{-1, -2, -9, -6};
    vector<vector<int>> qwe{{1,2,3},{4,5,6},{7,8,9}};
    string string1 = "abc3[cd]xyz";
    auto res = solution.decodeString(string1);
    cout << res << endl;
//    for (auto item: res)
//        cout << item << " ";
//    for (auto item: res) {
//        for (auto j: item) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
