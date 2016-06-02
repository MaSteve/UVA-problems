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
int visited[1002];

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
    int cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++) {
        int p, d;
        cin >> p >> d;
        AdjList.assign(p, vi());
        for (int k = 0; k < d; k++) {
            int i1, i2;
            cin >> i1 >> i2;
            AdjList[i1].push_back(i2);
            AdjList[i2].push_back(i1);
        }
        for (int k = 1; k < p; k++) {
            int num;
            for (int j = 0; j < p; j++) visited[j] = false;
            bfs(k, 0, num);
            printf("%d\n", num);
        }
        if (c != cases) printf("\n");
    }
    return 0;
}
