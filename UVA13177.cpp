#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int p, n;
    while (cin >> p >> n) {
        priority_queue<ii> pq;
        vector<int> v(n, 0), origin(n, 0);
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            pq.push(ii(val, i));
            origin[i] = val;
            v[i]++;
            p--;
        }
        while (!pq.empty() && p > 0) {
            ii val = pq.top();
            if (val.first <= 1) break;
            pq.pop();
            v[val.second]++;
            pq.push(ii(origin[val.second] / v[val.second] + (origin[val.second] % v[val.second] != 0? 1: 0), val.second));
            p--;
        }
        if (pq.empty()) printf("1\n");
        else printf("%d\n", pq.top().first);
    }
    return 0;
}
