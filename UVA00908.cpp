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
    bool first = false;
    while (cin >> N) {
        if (first) printf("\n");
        else first = true;
        int ccost = 0;
        for (int i = 0; i < N - 1; i++) {
            int s, d, c;
            cin >> s >> d >> c;
            ccost += c;
        }
        priority_queue<iii> pq;
        ds.clear(N);
        int K;
        cin >> K;
        for (int i = 0; i < K; i++) {
            int s, d, c;
            cin >> s >> d >> c;
            pq.push(iii(-c, ii(s-1, d-1)));
        }
        int M;
        cin >> M;
        for (int i = 0; i < M; i++) {
            int s, d, c;
            cin >> s >> d >> c;
            pq.push(iii(-c, ii(s-1, d-1)));
        }
        int ncost = 0;
        while (!pq.empty() && ds.numSets > 1) {
            iii line = pq.top(); pq.pop();
            if (!ds.isSameSet(line.second.first, line.second.second)) {
                ds.unionSet(line.second.first, line.second.second);
                ncost -= line.first;
            }
        }
        printf("%d\n%d\n", ccost, ncost);
    }
    return 0;
}
