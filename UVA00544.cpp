#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> road;
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

priority_queue<road> pq;
unordered_map<string, int> map;

int main() {
    int m, n, cases = 1;
    while (cin >> m >> n && !(m == 0 && n == 0)) {
        map.clear();
        printf("Scenario #%d\n", cases++);
        for (int i = 0; i < n; i++) {
            string k1, k2;
            int weight;
            cin >> k1 >> k2 >> weight;
            if (!map.count(k1)) map.insert(make_pair(k1, map.size()));
            if (!map.count(k2)) map.insert(make_pair(k2, map.size()));
            road l; l.second.first = map[k1]; l.second.second = map[k2];
            l.first = weight;
            pq.push(l);
        }
        string c1, c2;
        cin >> c1 >> c2;
        int i1 = map[c1], i2 = map[c2];
        ufds u(m);
        int w = 100000;
        while (!pq.empty()) {
            if (!u.isSameSet(pq.top().second.first, pq.top().second.second) && !(u.isSameSet(i1, i2))) {
                w = min(w, pq.top().first);
                u.unionSet(pq.top().second.first, pq.top().second.second);
            }
            pq.pop();
        }
        printf("%d tons\n", w);
        printf("\n");
    }
    return 0;
}
