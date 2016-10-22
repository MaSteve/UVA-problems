#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> v;
    while (cin >> N) {
        v.assign(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int M;
        cin >> M;
        auto low = lower_bound(v.begin(), v.end(), M/2);
        while (low != v.end()) {
            bool ok = binary_search(v.begin(), low, M - (*low));
            if (ok) {
                printf("Peter should buy books whose prices are %d and %d.\n\n",  M - (*low), (*low));
                break;
            }
            low++;
        }
    }
    return 0;
}
