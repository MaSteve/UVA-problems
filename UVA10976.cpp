#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<long long, long long> ll;

int main() {
    long long k;
    queue<ll> q;
    while (cin >> k) {
        long long x, y = k;
        while (true) {
            y++;
            x = (k*y)/(y-k);
            if (x < y) break;
            if (k == (x*y)/(x+y) && (x*y)%(x+y) == 0) q.push(ll(x, y));
        }
        printf("%lu\n", q.size());
        while (!q.empty()) {
            printf("1/%lld = 1/%lld + 1/%lld\n", k, q.front().first, q.front().second);
            q.pop();
        }
    }
    return 0;
}
