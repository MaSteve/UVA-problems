#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector<vi> AdjList;
vi times;

int n, k;
int T[5], F[5][100];

inline int abs(int x) {
    return x > 0? x: -x;
}

int dijkstra() {
    times.assign(100*n, 100000000);
    priority_queue<iii> pq;
    for (int i = 0; i < n; i++) {
        if (F[i][0]) pq.push(iii(0, ii(i, 0))), times[i] = 0;
    }
    while (!pq.empty()) {
        iii p = pq.top(); pq.pop();
        int t = -p.first, u = p.second.second, e = p.second.first;
        if (t > times[n*u + e]) continue;
        if (u == k) return t;
        for (int j = 0; j < AdjList[e].size(); j++) {
            int v = AdjList[e][j];
            if (t + abs(v-u)*T[e] < times[n*v + e]) {
                times[n*v + e] = t + abs(v-u)*T[e];
                pq.push(iii(-times[n*v + e], ii(e, v)));
            }
        }
        for (int i = 0; i < n; i++)
            if (i != e && F[i][u] && t + 60 < times[n*u + i]) {
                times[n*u + i] = t + 60;
                pq.push(iii(-times[n*u + i], ii(i, u)));
            }
    }
    return -1;
}

int main() {
    while (cin >> n >> k) {
        AdjList.assign(n, vi());
        for (int i = 0; i < n; i++) cin >> T[i];
        string s;
        getline(cin, s);
        memset(F, 0, n*400);
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            istringstream iss(s);
            int f;
            while (iss >> f) F[i][f] = 1, AdjList[i].push_back(f);
        }
        int ret = dijkstra();
        if (ret != -1) printf("%d\n", ret);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
