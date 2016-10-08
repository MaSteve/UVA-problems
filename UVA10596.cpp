#include <iostream>
#include <vector>
using namespace std;

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

vector<vi> AdjList;

int main() {
    int N, R;
    while (cin >> N >> R) {
        AdjList.assign(N, vi());
        ufds ds(N);
        for (int i = 0; i < R; i++) {
            int s, d;
            cin >> s >> d;
            AdjList[s].push_back(d);
            AdjList[d].push_back(s);
            ds.unionSet(s, d);
        }
        bool eulerian = R > 0;
        int f = -1;
        for (int i = 0; i < N && eulerian; i++) {
            if (AdjList[i].size()%2 != 0) eulerian = false;
            if (f == -1 && AdjList[i].size() > 0) f = i;
            else if (AdjList[i].size() > 0) eulerian = eulerian && ds.isSameSet(f, i);
        }
        if (eulerian) printf("Possible\n");
        else printf("Not Possible\n");
    }
    return 0;
}
