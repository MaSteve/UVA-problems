#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

unordered_map<string, int> m;
string ts[100];

bool kahn(vvi &adjList, vi &topo) {
    vi inDeg(adjList.size(), 0);
    for (int u = 0; u < adjList.size(); u++)
        for (int v = 0; v < adjList[u].size(); v++)
            inDeg[adjList[u][v]]++;
    priority_queue<int> q;
    for (int u = 0; u < inDeg.size(); u++)
        if (inDeg[u] == 0) q.push(-u);
    while (!q.empty()) {
        int u = -q.top(); q.pop();
        topo.push_back(u);
        for (int v = 0; v < adjList[u].size(); v++)
            if (--inDeg[adjList[u][v]] == 0) q.push(-adjList[u][v]);
    }
    for (int u = 0; u < inDeg.size(); u++)
        if (inDeg[u] != 0) return true;
    return false;
}

int main() {
    int N, c = 1;
    while (cin >> N) {
        m.clear();
        for (int i = 0; i < N; i++) {
            cin >> ts[i];
            m[ts[i]] = i;
        }
        int M;
        cin >> M;
        vvi adjList(N, vi());
        for (int i = 0; i < M; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            adjList[m[s1]].push_back(m[s2]);
        }
        vi topo;
        kahn(adjList, topo);
        printf("Case #%d: Dilbert should drink beverages in this order:", c);
        for (auto it = topo.begin(); it != topo.end(); ++it) {
            printf(" %s", ts[*it].c_str());
        }
        printf(".\n\n");
        c++;
    }
    return 0;
}
