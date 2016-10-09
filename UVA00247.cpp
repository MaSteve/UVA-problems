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
vi knocked;
int knocks;

vi dfs_num, dfs_low;
vector<bool> visited;
stack<int> s;
int counter, n0;

unordered_map<string, int> nametoid;
vector<string> idtoname;

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
        bool first = false;
        while (1) {
            if (first) printf(", ");
            else first = true;
            int v = s.top(); s.pop();
            visited[v] = 0;
            printf("%s", idtoname[v].c_str());
            if (n == v) break;
        }
        printf("\n");
    }
}

int main() {
    int n, m, c = 0;
    bool first = false;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        if (first) printf("\n");
        else first = true;
        c++;
        int id = 0;
        AdjList.assign(n, vi());
        idtoname.assign(n, "");
        nametoid.clear();
        for (int i = 0; i < m; i++) {
            string s, d;
            cin >> s >> d;
            if (!nametoid.count(s)) nametoid[s] = id, idtoname[id] = s, id++;
            if (!nametoid.count(d)) nametoid[d] = id, idtoname[id] = d, id++;
            AdjList[nametoid[s]].push_back(nametoid[d]);
        }

        n0 = counter = 0;
        dfs_num.assign(n, -1);
        dfs_low.assign(n, -1);
        visited.assign(n, false);

        printf("Calling circles for data set %d:\n", c);

        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == -1) scc(i, i);
        }
    }
    return 0;
}
