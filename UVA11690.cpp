#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;

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
    int o[10000];
    unordered_map<int, int> map;
    while (N--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> o[i];
        int x, y;
        ds.clear(n);
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            ds.unionSet(x, y);
        }
        map.clear();
        for (int i = 0; i < n; i++) map[ds.findSet(i)] += o[i];
        bool ok = true;
        for (auto it = map.begin(); it != map.end() && ok; ++it) {
            ok = ok && (it->second == 0);
        }
        if (ok) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
