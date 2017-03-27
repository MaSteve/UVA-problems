#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vi;

int N, M, mf, f, s, t, INF = 2000000;
int res[60][60];
vi p;

void augment(int v, int minEdge) {
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int main() {
    int T;
    vector<string> v[27];
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int n;
        cin >> n;
        for (int i = 0; i < n + 28; i++) {
            for (int j = 0; j < n + 28; j++) {
                res[i][j] = 0;
            }
        }
        for (int j = 1; j < n + 1; j++) {
            res[0][j] = 1;
        }
        for (int j = 0; j < n; j++) {
            res[n + 1 + j][n + 27] = 1;
        }
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            v[i].assign(k, "");
            for (int j = 0; j < k; j++) {
                cin >> v[i][j];
                transform(v[i][j].begin(), v[i][j].end(), v[i][j].begin(), ::tolower);
                v[i][j][0] = v[i][j][0] - 'a' + 'A';
                res[i + 1][n + 1 + v[i][j][0] - 'A'] = 1;
            }
        }
        N = n + 28;
        mf = 0;
        s = 0, t = n + 27;
        while (true) {
            f = 0;
            vi dist(N, INF); dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(N, -1);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int v = 0; v < N; v++) {
                    if (res[u][v] > 0 && dist[v] == INF) {
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                    }
                }
            }
            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }
        printf("Case #%d:\n", c);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (res[n + 1 + i][j + 1]) {
                    for (int k = 0; k < v[j].size(); k++) {
                        if (v[j][k][0] - 'A' == i) printf("%s\n", v[j][k].c_str());
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
