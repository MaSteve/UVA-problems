#include <iostream>
#include <vector>
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
    int N, E;
    while (cin >> N >> E) {
        ds.clear(256);
        for (int i = 0; i < E; i++) {
            char n1, n2;
            cin >> n1 >> n2;
            ds.unionSet(n1, n2);
        }
        printf("%d\n", - 255 + ds.numSets + E);
    }
    return 0;
}
