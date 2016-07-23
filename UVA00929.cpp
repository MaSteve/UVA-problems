#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> adjList;

int dijkstra(int S, int T) {
    vi dist(adjList.size(), INT_MAX);
    dist[S] = 0;
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(0, S));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (int j = 0; j < adjList[u].size(); j++) {
            ii v = adjList[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    return dist[T];
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int n, m;
        cin >> n >> m;
        adjList.assign(n*m, vii());
        vi cells(n*m, 0);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> cells[j*m + k];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (j-1 >= 0) adjList[j*m + k].push_back(make_pair((j-1)*m + k, cells[(j-1)*m + k]));
                if (j+1 < n) adjList[j*m + k].push_back(make_pair((j+1)*m + k, cells[(j+1)*m + k]));
                if (k-1 >= 0) adjList[j*m + k].push_back(make_pair(j*m + k-1, cells[j*m + k-1]));
                if (k+1 < m) adjList[j*m + k].push_back(make_pair(j*m + k+1, cells[j*m + k+1]));
            }
        }
        int d = dijkstra(0, n*m - 1);
        printf("%d\n", d + cells[0]);
    }
    return 0;
}
