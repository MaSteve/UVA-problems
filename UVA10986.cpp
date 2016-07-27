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
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        adjList.assign(n, vii());
        for (int j = 0; j < m; j++) {
            int s1, s2, lat;
            cin >> s1 >> s2 >> lat;
            adjList[s1].push_back(make_pair(s2, lat));
            adjList[s2].push_back(make_pair(s1, lat));
        }
        int d = dijkstra(S, T);
        printf("Case #%d: ", i);
        if (d == INT_MAX) printf("unreachable\n");
        else printf("%d\n", d);
    }
    return 0;
}
