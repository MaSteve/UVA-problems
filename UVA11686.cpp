#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;
int visited[1000000];
stack<int> sol;
bool ok;

void toposort(int j) {
    visited[j] = 1;
    for (int i = 0; i < AdjList[j].size() && ok; i++) {
        if (visited[AdjList[j][i]] == 0) {
            visited[AdjList[j][i]] = true;
            toposort(AdjList[j][i]);
        } else if (visited[AdjList[j][i]] == 1) {
            ok = false;
        }
    }
    visited[j] = 2;
    sol.push(j);
}

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        AdjList.assign(n, vi());
        while (m--) {
            int a, b;
            cin >> a >> b;
            AdjList[a-1].push_back(b-1);
        }
        for (int i = 0; i < n; i++) visited[i] = 0;
        ok = true;
        for (int i = 0; i < n && ok; i++) {
            if (visited[i] == 0) {
                visited[i] = true;
                toposort(i);
            }
        }
        if (!ok) {
            printf("IMPOSSIBLE\n");
            while (!sol.empty()) sol.pop();
        }
        else {
            while (!sol.empty()) {
                printf("%d\n", sol.top() + 1);
                sol.pop();
            }
        }
    }
    return 0;
}
