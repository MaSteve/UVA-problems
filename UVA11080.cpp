#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

vector<vi> adjList;
vi color;

int proc() {
    bool ok = true;
    int count = 0;
    queue<int> q;
    for (int j = 0; j < adjList.size() && ok; j++) {
        int black = 0, white = 0;
        if (color[j] == -1) {
            q.push(j);
            color[j] = 0;
        } else continue;
        while (!q.empty() && ok) {
            if (color[q.front()] == 0) black++;
            else white++;
            for (int i = 0; i < adjList[q.front()].size() && ok; i++) {
                if (color[adjList[q.front()][i]] == -1) {
                    color[adjList[q.front()][i]] = 1-color[q.front()];
                    q.push(adjList[q.front()][i]);
                } else if (color[adjList[q.front()][i]] == color[q.front()]) ok = false;
            }
            q.pop();
        }
        count += min(black, white);
        if (black == 0 || white == 0) count++;
    }
    return ok? count: -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int v, e;
        cin >> v >> e;
        adjList.assign(v, vi());
        color.assign(v, -1);
        for (int i = 0; i < e; i++) {
            int a1, a2;
            cin >> a1 >> a2;
            adjList[a1].push_back(a2);
            adjList[a2].push_back(a1);
        }
        printf("%d\n", proc());
    }
    return 0;
}
