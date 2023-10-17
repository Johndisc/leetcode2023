#include <iostream>
#include "global.h"
#include <ctime>

#include "n80.h"
#include "sort.h"

class C {
	int x;
	int y;
};
int main() {
//    Solution solution;
//    vector<int> asd{1,2,2};
//    vector<vector<char>> qwe{{'1','0','1','0','0'},
//							 {'1','0','1','1','1'},
//							 {'1','1','1','1','1'},
//							 {'1','0','0','1','0'}};
//    string string1 = "abc3[cd]xyz";
//	auto res = solution.removeDuplicates(asd);
//    cout << res << endl;
//    for (auto item: res)
//        cout << item << " ";
//    for (auto item: res) {
//        for (auto j: item) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }

	C* asd;
	asd = new C;
	shared_ptr<C> sp1(asd);
	shared_ptr<C> sp2(sp1);
	sp2.reset();
	cout << sp1.use_count() << endl;
    return 0;
}
