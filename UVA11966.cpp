#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef pair<int, ii> street;
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

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int N;
        double D;
        cin >> N >> D;
        D *= D;
        ufds u(N);
        vector<dd> v;
        for (int i = 0; i < N; i++) {
            double x, y;
            cin >> x >> y;
            for (int j = 0; j < i; j++) {
                if ((v[j].first-x)*(v[j].first-x) + (v[j].second-y)*(v[j].second-y) <= D) {
                    u.unionSet(i, j);
                }
            }
            v.push_back(make_pair(x, y));
        }
        printf("Case %d: %d\n", c, u.numSets);
    }
    return 0;
}
