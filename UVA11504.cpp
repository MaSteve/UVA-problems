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

struct ufds {
    vi p, r; int numSets;
    void clear(int N) {
        p.assign(N, 0); r.assign(N, 0); numSets = N;
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i]==i)? i: (p[i]=findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (r[x] > r[y]) p[y] = x;
            else {
                p[x] = y;
                if (r[x] == r[y]) r[y]++;
            } numSets--;
        }
    }
};

ufds ds;

vector<vi> AdjList;
vi knocked;
int knocks;

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
        while (1) {
            int v = s.top(); s.pop();
            visited[v] = 0;
            ds.unionSet(n, v);
            if (n == v) break;
        }
    }
}

void proc(int k) {
    k = ds.findSet(k);
    queue<int> q;
    knocks++;
    knocked[k] = 2;
    for (int i = 0; i < AdjList[k].size(); i++) {
        q.push(AdjList[k][i]);
    }
    while (!q.empty()) {
        if (!knocked[q.front()]) {
            knocked[q.front()] = 1;
            for (int i = 0; i < AdjList[q.front()].size(); i++) {
                q.push(AdjList[q.front()][i]);
            }
        } else if (ds.findSet(q.front()) != k && knocked[ds.findSet(q.front())] == 2) knocks--, knocked[ds.findSet(q.front())] = 1;
        q.pop();
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        AdjList.assign(n, vi());
        for (int i = 0; i < m; i++) {
            int s, d;
            cin >> s >> d;
            AdjList[s-1].push_back(d-1);
        }

        n0 = counter = 0;
        dfs_num.assign(n, -1);
        dfs_low.assign(n, -1);
        visited.assign(n, false);
        ds.clear(n);
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == -1) scc(i, i);
        }

        knocked.assign(n, false);
        knocks = 0;
        for (int i = 0; i < n; i++) {
            if (!knocked[i]) proc(i);
        }
        printf("%d\n", knocks);
    }
    return 0;
}
