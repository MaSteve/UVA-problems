#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int mask[10];
    for (int i = 1; i <= 5001; i++) {
        int ch = i;
        for (int j = 0; j < 10; j++) mask[j] = false;
        bool ok = true;
        while (ch && ok) {
            int val = ch%10;
            ch /= 10;
            ok = !mask[val];
            mask[val] = true;
        }
        if (ok) v.push_back(i);
    }
    int N, M;
    while (cin >> N >> M) {
        printf("%ld\n", upper_bound(v.begin(), v.end(), M) - lower_bound(v.begin(), v.end(), N));
    }
    return 0;
}
