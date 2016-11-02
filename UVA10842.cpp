#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct ufds {
    vi p, r; int numSets;
    void clear(int N) {
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

ufds ds;

int main() {
    int N;
    cin >> N;
    for (int c = 1; c <= N; c++) {
        int n, m;
        cin >> n >> m;
        priority_queue<iii> pq;
        ds.clear(n);
        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            pq.push(iii(c, ii(u, v)));
        }
        int min = 10000;
        while (!pq.empty() && ds.numSets > 1) {
            iii road = pq.top(); pq.pop();
            ds.unionSet(road.second.first, road.second.second);
            min = road.first;
        }
        printf("Case #%d: %d\n", c, min);
    }
    return 0;
}
