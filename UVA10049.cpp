#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int last = 5;
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    for (int i = 4; true; i++) {
        int res = lower_bound(v.begin(), v.end(), i) - v.begin();
        last += res;
        v.push_back(last);
        if (last > 2000000000) break;
    }
    int n;
    while (cin >> n && n != 0) {
        int res = lower_bound(v.begin(), v.end(), n) - v.begin();
        printf("%d\n", res);
    }
    return 0;
}
