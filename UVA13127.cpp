#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;

int main() {
    int N, M, B, P;
    while (cin >> N >> M >> B >> P) {
        AdjList.assign(N + 2, vii());
        for (int i = 0; i < M; i++) {
            int U, V, T;
            cin >> U >> V >> T;
            AdjList[U].push_back(make_pair(V, T));
            AdjList[V].push_back(make_pair(U, T));
        }
        vi banks, polices;
        for (int i = 0; i < B; i++) {
            int b;
            cin >> b;
            banks.push_back(b);
        }
        for (int i = 0; i < P; i++) {
            int p;
            cin >> p;
            AdjList[N].push_back(make_pair(p, 0));
            AdjList[p].push_back(make_pair(N, 0));
            polices.push_back(p);
        }
        vi dist(N+2, 1000000000); dist[N] = 0;
        priority_queue<ii> pq;
        pq.push(make_pair(0, N));
        while (!pq.empty()) {
            ii front = pq.top(); pq.pop();
            int d = -front.first, u = front.second;
            if (d > dist[u]) continue;
            for (int j = 0; j < AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(make_pair(-dist[v.first], v.first));
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < B; i++) {
            if (dist[banks[i]] > maxi) maxi =  dist[banks[i]];
        }
        int E = maxi, S = 0;
        sort(banks.begin(), banks.end());
        queue<int> q;
        for (int i = 0; i < B; i++) {
            if (dist[banks[i]] == E) q.push(banks[i]), S++;
        }
        printf("%d ", S);
        if (E == 1000000000) {
            printf("*\n");
        } else printf("%d\n", E);
        bool first = false;
        while (!q.empty()) {
            if (first) printf(" ");
            else first = true;
            printf("%d", q.front());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}
