#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<double, double> point;
typedef pair<int, int> ii;
typedef pair<double, ii> line;
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

priority_queue<line> pq;
vector<point> v;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        v.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            v.push_back(point(x,y));
            for (int j = 0; j < v.size() - 1; j++) {
                line l; l.second.first = j; l.second.second = i;
                double dx = x - v[j].first, dy = y - v[j].second;
                l.first = -sqrt(dx*dx + dy*dy);
                pq.push(l);
            }
        }
        ufds u(n);
        double d = 0;
        while (!pq.empty()) {
            if (!u.isSameSet(pq.top().second.first, pq.top().second.second)) {
                d -= pq.top().first;
                u.unionSet(pq.top().second.first, pq.top().second.second);
            }
            pq.pop();
        }
        printf("%.2f\n", d);
        if (cases) printf("\n");
    }
    return 0;
}
