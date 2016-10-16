#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
bitset<21> visited;

int proc(int A, int B) {
    queue<int> q;
    visited.reset();
    q.push(A);
    visited.set(A);
    while (!q.empty()) {
        int d = q.front()/100, node = q.front()%100;
        q.pop();
        if (node == B) return d;
        for (int i = 0; i < AdjList[node].size(); i++) {
            if (!visited[AdjList[node][i]]) q.push((d+1)*100 + AdjList[node][i]), visited.set(AdjList[node][i]);
        }
    }
    return -1;
}

int main() {
    int n, c = 1;
    while (cin >> n) {
        AdjList.assign(20, vi());
        int v = 0;
        do {
            for (int i = 0; i < n; i++) {
                int auxi;
                cin >> auxi;
                AdjList[v].push_back(auxi-1);
                AdjList[auxi-1].push_back(v);
            }
            v++;
            cin >> n;
        } while (v < 19);
        printf("Test Set #%d\n", c);
        for (int i = 0; i < n; i++) {
            int A, B;
            cin >> A >> B;
            printf("%2d to %2d: %d\n", A, B, proc(A-1, B-1));
        }
        printf("\n");
        c++;
    }
    return 0;
}
