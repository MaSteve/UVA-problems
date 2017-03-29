#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


bool bellman_ford(int s, vector<vii> &adjList, vi &dist, vi &relax) {
    relax.assign(adjList.size(), 0);
    dist.assign(adjList.size(), ll(1) << 40); dist[s] = 0;
    bool relaxed;
    for (int i = 0; i < adjList.size(); i++) {
        relaxed = false;
        for (int u = 0; u < adjList.size(); u++)
            for (int j = 0; j < adjList[u].size(); j++) {
                ii v = adjList[u][j];
                if (dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                    relaxed = true;
                    if (i == adjList.size() - 1) relax[v.first] = 1;
                }
            }
        if (!relaxed) return false;
    }
    return relaxed;
}

void proc(vector<vii> &adjList, vi &relax) {
    int n = adjList.size();
    vi visited(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (relax[i] && !visited[i]) {
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                if (!visited[node]) {
                    visited[node] = 1;
                    relax[node] = 1;
                    for (int j = 0; j < adjList[node].size(); j++) {
                        q.push(adjList[node][j].first);
                    }
                }
            }
        }
    }
}

int main() {
    int n, c = 1;
    vi busy, dist, relax;
    vector<vii> adjList;
    while (cin >> n) {
        printf("Set #%d\n", c++);
        if (n != 0) {
            busy.assign(n, 0);
            adjList.assign(n, vii());
        }
        for (int i = 0; i < n; i++) cin >> busy[i];
        int r;
        cin >> r;
        for (int i = 0; i < r; i++) {
            int s, d;
            cin >> s >> d;
            s--, d--;
            int b = busy[d] - busy[s];
            adjList[s].push_back(ii(d, b*b*b));
        }
        bool relaxed;
        if (n != 0) relaxed = bellman_ford(0, adjList, dist, relax);
        if (relaxed) proc(adjList, relax);
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int val;
            cin >> val;
            if (dist[val - 1] < 3 || relax[val - 1] || dist[val - 1] > (ll(1) << 32)) printf("?\n");
            else printf("%lld\n", dist[val - 1]);
        }
    }
}
