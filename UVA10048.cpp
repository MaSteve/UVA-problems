#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
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

priority_queue<street> pq;

int main() {
    bool first = false;
    int C, S, Q, c = 1;
    while (cin >> C >> S >> Q && !(C == 0 && S == 0 && Q == 0)) {
        if (first) printf("\n");
        else first = true;
        for (int i = 0; i < S; i++) {
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            street s = make_pair(-d, make_pair(c1-1, c2-1));
            pq.push(s);
        }
        ufds u(C);
        unordered_map<int, int> noise;
        while (!pq.empty()) {
            if (!u.isSameSet(pq.top().second.first, pq.top().second.second)) {
                for (int i = 0; i < C; i++) {
                    if (u.isSameSet(pq.top().second.first, i))
                        for (int j = 0; j < C; j++) {
                            if (u.isSameSet(pq.top().second.second, j))
                                noise[i*1000+j] = noise[i+1000*j] = max(noise[i*1000+pq.top().second.first], max(noise[j*1000+pq.top().second.second], -pq.top().first));
                        }
                }
                u.unionSet(pq.top().second.first, pq.top().second.second);
            }
            pq.pop();
        }
        printf("Case #%d\n", c);
        c++;
        while (Q--) {
            int c1, c2;
            cin >> c1 >> c2;
            c1--, c2--;
            if (u.isSameSet(c1, c2)) printf("%d\n", noise[c1*1000 + c2]);
            else printf("no path\n");
        }
    }
    return 0;
}
