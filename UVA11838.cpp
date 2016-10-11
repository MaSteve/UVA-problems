#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vi> AdjList;

vi dfs_num, dfs_low;
vector<bool> visited;
stack<int> s;
int counter, n0;

void scc(int n, int p) {
    visited[n] = true;
    s.push(n);
    dfs_num[n] = dfs_low[n] = counter++;
    for (int i = 0; i < AdjList[n].size(); i++) {
        if (dfs_num[AdjList[n][i]] == -1) {
            scc(AdjList[n][i], n);
        }
        if (visited[AdjList[n][i]]) dfs_low[n] = min(dfs_low[n], dfs_low[AdjList[n][i]]);
    }
    if (dfs_num[n] == dfs_low[n]) {
        n0++;
        while (1) {
            int v = s.top(); s.pop();
            visited[v] = 0;
            if (n == v) break;
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        AdjList.assign(n, vi());
        for (int i = 0; i < m; i++) {
            int s, d, w;
            cin >> s >> d >> w;
            AdjList[s-1].push_back(d-1);
            if (w == 2) AdjList[d-1].push_back(s-1);
        }

        n0 = counter = 0;
        dfs_num.assign(n, -1);
        dfs_low.assign(n, -1);
        visited.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == -1) scc(i, i);
        }
        printf("%d\n", n0 > 1? 0: 1);
    }
    return 0;
}
