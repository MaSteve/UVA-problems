#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vi;

int P, S, C, M, mf, f, s, t, INF = 2000000;
int res[522][522];
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
    int N;
    cin >> N;
    while (N--) {
        cin >> P >> S >> C >> M;
        for (int i = 0; i < P+S+2; i++)
            for (int j = 0; j < P+S+2; j++)
                res[i][j] = 0;

        for (int i = 0; i < M; i++) {
            int c, p;
            cin >> c >> p;
            res[c][p+P] = 1;
        }
        for (int i = 1; i <= P; i++) res[0][i] = 1;
        for (int i = 1; i <= S; i++) res[i+P][P+S+1] = C;
        s = 0, t = P+S+1;

        mf = 0;
        while (true) {
            f = 0;
            vi dist(P+S+2, INF); dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(P+S+2, -1);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int v = 0; v < P+S+2; v++) {
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
