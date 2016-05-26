#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> AdjList;
int ind;
unordered_map<string, int> map;
int visited[40];

void bfs(int i, int j, int & acum) {
    acum = -1;
    queue<ii> q;
    q.push(make_pair(i, 0));
    while (!q.empty()) {
        ii n = q.front();
        q.pop();
        if (n.first == j) {
            acum = n.second;
            break;
        }
        if (visited[n.first]) continue;
        visited[n.first] = true;
        for (int j = 0; j < AdjList[n.first].size(); j++)
            q.push(make_pair(AdjList[n.first][j], n.second + 1));
    }
}

int main() {
    printf("SHIPPING ROUTES OUTPUT\n\n");
    int cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++) {
        printf("DATA SET  %d\n\n", c);
        int m, n, p, j;
        cin >> m >> n >> p;
        ind = 0;
        map.clear();
        AdjList.assign(m, vi());
        for (; ind < m; ind++) {
            string s;
            cin >> s;
            map[s] = ind;
        }
        for (int k = 0; k < n; k++) {
            string s1, s2;
            cin >> s1 >> s2;
            AdjList[map[s1]].push_back(map[s2]);
            AdjList[map[s2]].push_back(map[s1]);
        }
        for (int k = 0; k < p; k++) {
            int size;
            string s1, s2;
            cin >> size >> s1 >> s2;
            int cost = 0;
            for (int k = 0; k < ind; k++) visited[k] = false;
            bfs(map[s1], map[s2], cost);
            if (cost != -1) printf("$%d\n", cost*size*100);
            else printf("NO SHIPMENT POSSIBLE\n");
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
