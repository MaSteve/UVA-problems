#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;
bool visited[100];
bool first;

void toposort(int j) {
    for (int i = 0; i < AdjList[j].size(); i++) {
        if (!visited[AdjList[j][i]]) {
            visited[AdjList[j][i]] = true;
            toposort(AdjList[j][i]);
        }
    }
    if (!first) first = true;
    else printf(" ");
    printf("%d", j+1);
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && !(n == 0 && m == 0)) {
        for (int i = 0; i < n; i++) visited[i] = false;
        AdjList.assign(n, vi());
        while (m--) {
            int i, j;
            scanf("%d %d", &i, &j);
            AdjList[j-1].push_back(i-1);
        }
        first = false;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                toposort(i);
            }
        }
        printf("\n");
    }
    return 0;
}
