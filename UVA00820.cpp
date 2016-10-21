#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vi;

int N, M, mf, f, s, t, INF = 2000000;
int res[100][100];
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
    int cases = 1;
    while (cin >> N && N) {
        int c;
        cin >> s >> t >> c;
        s--, t--;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res[i][j] = 0;
        for (int i = 0; i < c; i++) {
            int n1, n2, b;
            cin >> n1 >> n2 >> b;
            res[n1-1][n2-1] += b, res[n2-1][n1-1] += b;
        }

        mf = 0;
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
        printf("Network %d\nThe bandwidth is %d.\n\n", cases, mf);
        cases++;
    }
    return 0;
}
