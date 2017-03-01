#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
    ii vec[1000010];
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            vec[i] = ii(val, i);
        }
        sort(vec, vec + n);
        for (int i = 0; i < m; i++) {
            int k, v;
            cin >> k >> v;
            int p1 = lower_bound(vec, vec + n, ii(v, -1)) - vec;
            int p2 = lower_bound(vec, vec + n, ii(v, n + 1)) - vec;
            if (k > p2 - p1) printf("0\n");
            else printf("%d\n", vec[p1+k-1].second + 1);
        }
    }
    return 0;
}
