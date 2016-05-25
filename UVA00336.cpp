#include <cstdio>
#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> AdjList;
int ind;
unordered_map<int, int> m;
int visited[40];

void bfs(int i, int ttl, int & acum) {
    queue<ii> q;
    q.push(make_pair(i, ttl));
    while (!q.empty()) {
        ii n = q.front();
        q.pop();
        if (visited[n.first]) continue;
        visited[n.first] = true;
        acum++;
        for (int j = 0; j < AdjList[n.first].size() && (n.second); j++)
            q.push(make_pair(AdjList[n.first][j], n.second - 1));
    }
}

int main() {
    int edges, cases = 1;
    while (scanf("%d", &edges) && !(edges == 0)) {
        int i, j;
        ind = 0;
        AdjList.assign(40, vi());
        m.clear();
        for (int k = 0; k < edges; k++) {
            scanf("%d %d", &i, &j);
            if (!m.count(i)) m[i] = ind, ind++;
            if (!m.count(j)) m[j] = ind, ind++;
            AdjList[m[i]].push_back(m[j]);
            AdjList[m[j]].push_back(m[i]);
        }
        while (scanf("%d %d", &i, &j) && !(i == 0 && j == 0)) {
            int n = 0;
            for (int k = 0; k < ind; k++) visited[k] = false;
            bfs(m[i], j, n);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cases++, ind-n, i, j);
        }
    }
    return 0;
}
