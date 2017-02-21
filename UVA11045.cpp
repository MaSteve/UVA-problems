#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vi;

int N, M, mf, f, s, t, INF = 2000000;
int res[40][40];
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

inline int toi(string s) {
    if (s == "XXL") return 1;
    if (s == "XL") return 2;
    if (s == "L") return 3;
    if (s == "M") return 4;
    if (s == "S") return 5;
    if (s == "XS") return 6;
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        s = 0, t = 7 + M;
        for (int i = 0; i < 8 + M; i++)
            for (int j = 0; j < 8 + M; j++)
                res[i][j] = 0;
        for (int i = 1; i <= 6; i++) res[0][i] = res[i][0] = N/6;
        for (int i = 0; i < M; i++) {
            string s1, s2;
            int s_1, s_2;
            cin >> s1 >> s2;
            s_1 = toi(s1), s_2 = toi(s2);
            res[s_1][i+7] = res[i+7][s_1] = 1;
            res[s_2][i+7] = res[i+7][s_2] = 1;
            res[t][i+7] = res[i+7][t] = 1;
        }
        N = 8 + M;
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
        if (mf == M) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
