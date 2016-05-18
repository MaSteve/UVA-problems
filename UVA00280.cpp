#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;
bool visited[100];

void visit(int v, int & count) {
    if (visited[v]) return;
    visited[v] = true, count++;
    for (int i = 0; i < AdjList[v].size(); i++) {
        visit(AdjList[v][i], count);
    }
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        AdjList.assign(n, vi());
        int v;
        while (cin >> v && v != 0) {
            int d;
            while (cin >> d && d != 0) {
                AdjList[v-1].push_back(d-1);
            }
        }
        int c;
        cin >> c;
        while (c--) {
            for (int i = 0; i < n; i++) visited[i] = false;
            cin >> v;
            int count = 0;
            for (int i = 0; i < AdjList[v-1].size(); i++) {
                visit(AdjList[v-1][i], count);
            }
            printf("%d", n - count);
            for (int i = 0; i < n; i++) if (!visited[i]) printf(" %d", i+1);
            printf("\n");
        }
    }
    return 0;
}
