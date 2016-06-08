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
    int cases;
    cin >> cases;
    while (cases--) {
        int N, M;
        cin >> N >> M;
        ufds friends(N);
        while (M--) {
            int A, B;
            cin >> A >> B;
            friends.unionSet(A-1, B-1);
        }
        int r = friends.biggestSubSetSize();
        if (r == 1) r = 0;
        printf("%d\n", r);
    }
    return 0;
}
