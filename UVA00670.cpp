#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int mf, f, s, t, INF = 2000000;
int res[204][204];
vi p;

inline double dis(int x0, int y0, int x1, int y1) {
    return sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
}

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
    int L;
    cin >> L;
    while (L--) {
        int N, M;
        cin >> N >> M;
        vector<ii> v(N, ii(0, 0));
        vector<ii> P(M, ii(0, 0));
        for (int i = 0; i < N; i++) {
            cin >> v[i].first >> v[i].second;
        }
        for (int i = 0; i < M; i++) {
            cin >> P[i].first >> P[i].second;
        }
        for (int i = 0; i < N+M+1; i++)
            for (int j = 0; j < N+M+1; j++)
                res[i][j] = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M; j++) {
                if (dis(v[i].first, v[i].second, P[j].first, P[j].second) + dis(v[i+1].first, v[i+1].second, P[j].first, P[j].second) <= 2*dis(v[i].first, v[i].second, v[i+1].first, v[i+1].second)) {
                    res[i+1][j+N] = 1;
                }
            }
        }
        for (int i = 1; i < N; i++) res[0][i] = 1;
        for (int i = 0; i < M; i++) res[i+N][N+M] = 1;

        s = 0, t = N+M;

        mf = 0;
        while (true) {
            f = 0;
            vi dist(N+M+1, INF); dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(N+M+1, -1);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int v = 0; v < N+M+1; v++) {
                    if (res[u][v] > 0 && dist[v] == INF) {
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
                    }
                }
            }
            augment(t, INF);
            if (f == 0) break;
            mf += f;
         }
         printf("%d\n", mf + N);
         for (int i = 0; i < N - 1; i++) {
             printf("%d %d ", v[i].first, v[i].second);
             for (int j = 0; j < M; j++) {
                 if (res[j+N][i+1]) {
                     printf("%d %d ", P[j].first, P[j].second);
                     break;
                 }
             }
         }
         printf("%d %d\n", v[N-1].first, v[N-1].second);
         if (L) printf("\n");
    }
    return 0;
}
