#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int val;
        cin >> val;
        auto low = lower_bound(v.begin(), v.end(), val);
        auto up = upper_bound(v.begin(), v.end(), val);
        int l = low - v.begin() - 1, h = up - v.begin();
        if (l >= 0 && l < v.size()) printf("%d ", v[l]);
        else printf("X ");
        if (h >= 0 && h < v.size()) printf("%d\n", v[h]);
        else printf("X\n");
    }
    return 0;
}
