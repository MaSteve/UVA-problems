#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct ufds {
    vii p; vi r; int numSets, BSS = 1;
    ufds(int N) {
        p.assign(N, ii(0, 1)); r.assign(N, 0); numSets = N;
        for (int i = 0; i < N; i++) p[i].first = i;
    }
    int subSetSize(int i) {
        int x = findSet(i);
        return p[x].second;
    }
    int biggestSubSetSize() { return BSS; }
    int findSet(int i) { return (p[i].first==i)? i: (p[i].first=findSet(p[i].first)); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (r[x] > r[y]) p[y].first = x, p[x].second += p[y].second, BSS = max(BSS, p[x].second);
            else {
                p[x].first = y;
                p[y].second += p[x].second;
                BSS = max(BSS, p[y].second);
                if (r[x] == r[y]) r[y]++;
            } numSets--;
        }
    }
};

int main() {
    int N, M, cases = 1;
    while (cin >> N >> M && !(N == 0 && M == 0)) {
        ufds religions(N);
        while (M--) {
            int i, j;
            cin >> i >> j;
            religions.unionSet(i-1, j-1);
        }
        printf("Case %d: %d\n", cases++, religions.numSets);
    }
    return 0;
}
