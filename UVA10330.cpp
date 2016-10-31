#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

typedef vector<int> vi;

int N, mf, f, s, t, INF = INT_MAX;
int res[202][202];
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
    while (cin >> N) {
        for (int i = 0; i < 2*N + 2; i++)
            for (int j = 0; j < 2*N + 2; j++)
                res[i][j] = 0;
        for (int i = 1; i <= N; i++) {
            int c;
            cin >> c;
            res[2*i][(2*i)+1] = c;
        }
        int M;
        cin >> M;
        for (int i = 0; i < M; i++) {
            int j, k, c;
            cin >> j >> k >> c;
            res[(2*j)+1][2*k] = c;
        }
        int B, D;
        cin >> B >> D;
        for (int i = 0; i < B; i++) {
            int k;
            cin >> k;
            res[0][2*k] = INF;
        }
        for (int i = 0; i < D; i++) {
            int k;
            cin >> k;
            res[(2*k)+1][1] = INF;
        }
        s = mf = 0, t = 1;
        while (true) {
            f = 0;
            vi dist(2*N + 2, INF); dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(2*N + 2, -1);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int v = 0; v < 2*N + 2; v++) {
                    if (res[u][v] > 0 && dist[v] == INF) {
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                    }
                }
            }
            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }
        printf("%d\n", mf);
    }
    return 0;
}
