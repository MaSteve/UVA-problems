#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

typedef vector<int> vi;

int M, W, mf, f, s, t, INF = INT_MAX;
int res[102][102];
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
    while (cin >> M >> W && !(M == 0 && W == 0)) {
        for (int i = 0; i < 2*(M-1); i++)
            for (int j = 0; j < 2*(M-1); j++)
                res[i][j] = 0;
        for (int i = 0; i < M-2; i++) {
            int id, c;
            cin >> id >> c;
            id--;
            res[2*id][(2*id)+1] = c;
        }
        for (int i = 0; i < W; i++) {
            int j, k, c;
            cin >> j >> k >> c;
            j--, k--;
            if (j > k) {
                int auxi = k;
                k = j;
                j = auxi;
            }
            if (j == 0 && k == M-1) res[0][1] = res[1][0] = c;
            else if (j == 0) res[0][2*k] = res[(2*k)+1][0] = c;
            else if (k == M-1) res[1][2*j] = res[(2*j)+1][1] = c;
            else res[(2*j)+1][2*k] = res[(2*k)+1][2*j] = c;
        }
        s = mf = 0, t = 1;
        while (true) {
            f = 0;
            vi dist(2*(M-1), INF); dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(2*(M-1), -1);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int v = 0; v < 2*(M-1); v++) {
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
