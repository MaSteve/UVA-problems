#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

typedef vector<int> vi;

vector<vi> adjList;
vi color;

bool proc() {
    bool ok = true;
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while (!q.empty() && ok) {
        for (int i = 0; i < adjList[q.front()].size() && ok; i++) {
            if (color[adjList[q.front()][i]] == -1) {
                color[adjList[q.front()][i]] = 1-color[q.front()];
                q.push(adjList[q.front()][i]);
            } else if (color[adjList[q.front()][i]] == color[q.front()]) ok = false;
        }
        q.pop();
    }
    return ok;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        adjList.assign(n, vi());
        color.assign(n, -1);
        int l;
        cin >> l;
        for (int i = 0; i < l; i++) {
            int a1, a2;
            cin >> a1 >> a2;
            adjList[a1].push_back(a2);
            adjList[a2].push_back(a1);
        }
        bool ok = proc();
        if (ok) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
