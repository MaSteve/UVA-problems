#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> tunnel;
typedef vector<int> vi;

struct ufds {
    vi p, r; int numSets;
    ufds(int N) {
        p.assign(N, 0); r.assign(N, 0); numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i]==i)? i: (p[i]=findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (r[x] > r[y]) p[y] = x;
            else {
                p[x] = y;
                if (r[x] == r[y]) r[y]++;
            } numSets--;
        }
    }
};

priority_queue<tunnel> pq;

int main() {
    char trash;
    int cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cost;
                cin >> cost;
                if (j != n - 1) cin >> trash;
                if (cost != 0) {
                    tunnel l; l.second.first = -i; l.second.second = -j;
                    l.first = -cost;
                    pq.push(l);
                }
            }
        }
        ufds u(n);
        printf("Case %d:\n", c);
        while (!pq.empty()) {
            if (!u.isSameSet(-pq.top().second.first, -pq.top().second.second)) {
                printf("%c-%c %d\n", -pq.top().second.first + 'A', -pq.top().second.second + 'A', -pq.top().first);
                u.unionSet(-pq.top().second.first, -pq.top().second.second);
            }
            pq.pop();
        }
    }
    return 0;
}
