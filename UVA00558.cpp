#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool bellmanford(vector<vii> & AdjList, int V) {
    int s = 0;
    vi dist(V, 100000000); dist[s] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
        }
    }
    bool neg = false;
    for (int u = 0; u < V && !neg; u++) {
        for (int j = 0; j < (int)AdjList[u].size() && !neg; j++) {
            ii v = AdjList[u][j];
            if (dist[u] + v.second < dist[v.first]) neg = true;
        }
    }
    return neg;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        vector<vii> AdjList(n, vii());
        for (int i = 0; i < m; i++) {
            int x, y, t;
            cin >> x >> y >> t;
            AdjList[x].push_back(make_pair(y, t));
        }
        bool neg = bellmanford(AdjList, n);
        if (neg) printf("possible\n");
        else  printf("not possible\n");
    }
    return 0;
}
