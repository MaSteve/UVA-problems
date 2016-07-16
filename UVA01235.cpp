#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> roll;
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

int dist(int k1, int k2) {
    int d = 0;
    for (int i = 0; i < 4; i++) {
        int mini = min(k1%10, k2%10), maxi = max(k1%10, k2%10);
        d += min(maxi-mini, 10 + mini - maxi);
        k1 /= 10; k2 /= 10;
    }
    return d;
}

priority_queue<roll> pq;
vi v;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        v.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            v.push_back(k);
            for (int j = 0; j < v.size() - 1; j++) {
                roll l; l.second.first = j; l.second.second = i;
                l.first = -dist(k, v[j]);
                pq.push(l);
            }
        }
        ufds u(n + 1);
        int d = 0;
        while (!pq.empty()) {
            if (!u.isSameSet(pq.top().second.first, pq.top().second.second)) {
                d -= pq.top().first;
                u.unionSet(pq.top().second.first, pq.top().second.second);
            }
            pq.pop();
        }
        int m = 50;
        for (int i = 0; i < v.size(); i++) m = min(m, dist(0, v[i]));
        d += m;
        printf("%d\n", d);
    }
    return 0;
}
