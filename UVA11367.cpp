#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

vi prices;
int costs[1000][102];
vector<vii> AdjList;
int c, s, e, N, M;

int dijkstra() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 102; j++)
            costs[i][j] = 100000000;
    costs[s][0] = 0;
    priority_queue<iii> pq;
    pq.push(iii(0, ii(0, s)));
    while (!pq.empty()) {
        iii p = pq.top(); pq.pop();
        int cost = -p.first, u = p.second.second, g = p.second.first;
        if (cost > costs[u][g]) continue;
        if (u == e) return cost;
        for (int j = 0; j < AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (g - v.second >= 0 && (cost < costs[v.first][g - v.second])) {
                costs[v.first][g - v.second] = cost;
                pq.push(iii(-cost, ii(g - v.second, v.first)));
            }
        }
        if (g < c && costs[u][g+1] > cost+prices[u]) {
            costs[u][g+1] = cost+prices[u];
            pq.push(iii(-(cost+prices[u]), ii(g+1, u)));
        }
    }
    return -1;
}

int main() {
    while (cin >> N >> M) {
        prices.assign(N, 0);
        AdjList.assign(N, vii());
        for (int i = 0; i < N; i++) cin >> prices[i];
        for (int i = 0; i < M; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            AdjList[u].push_back(ii(v, d));
            AdjList[v].push_back(ii(u, d));
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> c >> s >> e;
            int ret = dijkstra();
            if (ret != -1) printf("%d\n", ret);
            else printf("impossible\n");
        }
    }
    return 0;
}
