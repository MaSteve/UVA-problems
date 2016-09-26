#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_set>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool bellmanford(vector<vii> & AdjList, vi & energy, int V) {
    int s = 0;
    vi dist(V, 100000000); dist[s] = -100;
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                int value = min(dist[v.first], dist[u] - energy[v.first]);
                if (value < 0) dist[v.first] = value;
            }
        }
    }
    if (dist[V-1] < 0) return true;

    vi nodes;
    for (int u = 0; u < V; u++) {
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[u] - energy[v.first] < dist[v.first] && dist[u] - energy[v.first] < 0) nodes.push_back(v.first);
        }
    }

    queue<int> reachable;
    for (int i = 0; i < nodes.size(); i++) {
        unordered_set<int> visited;
        visited.insert(nodes[i]);
        reachable.push(nodes[i]);
        while (!reachable.empty()) {
            int u = reachable.front();
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                if (AdjList[u][j].first == V-1) return true;
                else if (!visited.count(AdjList[u][j].first)) reachable.push(AdjList[u][j].first), visited.insert(AdjList[u][j].first);
            }
            reachable.pop();
        }
    }
    return false;
}

int main() {
    int n;
    while (cin >> n && n != -1) {
        vector<vii> AdjList(n, vii());
        vi energy(n, 0);
        for (int i = 0; i < n; i++) {
            int r;
            cin >> energy[i] >> r;
            for (int j = 0; j < r; j++) {
                int d;
                cin >> d;
                AdjList[i].push_back(make_pair(d - 1, 0));
            }
        }
        bool neg = bellmanford(AdjList, energy, n);
        if (neg) printf("winnable\n");
        else  printf("hopeless\n");
    }
    return 0;
}
