#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vi;

int Bolts, Nuts, mf, f, s, t, INF = 2000000;
int res[1004][1004];
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
    for (int cases = 1; cases <= N; cases++) {
        cin >> Bolts >> Nuts;
        for (int i = 0; i < Bolts+Nuts+2; i++)
            for (int j = 0; j < Bolts+Nuts+2; j++)
                res[i][j] = 0;

        for (int i = 1; i <= Bolts; i++)
            for (int j = 1; j <= Nuts; j++)
                cin >> res[i][j+Bolts];

        for (int i = 1; i <= Bolts; i++) res[0][i] = 1;
        for (int i = 1; i <= Nuts; i++) res[i+Bolts][Bolts+Nuts+1] = 1;
        s = 0, t = Bolts+Nuts+1;
        mf = 0;
        while (true) {
            f = 0;
            vi dist(Bolts+Nuts+2, INF); dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(Bolts+Nuts+2, -1);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int v = 0; v < Bolts+Nuts+2; v++) {
                    if (res[u][v] > 0 && dist[v] == INF) {
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                    }
                }
            }
            augment(t, INF);
            if (f == 0) break;
            mf += f;
         }
         printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", cases, mf);
    }
    return 0;
}
