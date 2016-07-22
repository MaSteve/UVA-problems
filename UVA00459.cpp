#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<int> vi;

vector<vi> adjList;
vi color;

int proc() {
    bool ok = true;
    int count = 0;
    queue<int> q;
    for (int j = 0; j < adjList.size() && ok; j++) {
        if (color[j] == -1) {
            q.push(j);
            color[j] = 0;
            count++;
        }
        while (!q.empty() && ok) {
            for (int i = 0; i < adjList[q.front()].size() && ok; i++) {
                if (color[adjList[q.front()][i]] == -1) {
                    color[adjList[q.front()][i]] = 0;
                    q.push(adjList[q.front()][i]);
                }
            }
            q.pop();
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        char V;
        cin >> V;
        adjList.assign(V-'A'+1, vi());
        color.assign(V-'A'+1, -1);
        string s;
        getline(cin, s);
        while (getline(cin, s) && s != "") {
            int a1 = s[0]-'A', a2 = s[1]-'A';
            adjList[a1].push_back(a2);
            adjList[a2].push_back(a1);
        }
        printf("%d\n", proc());
        if (T) printf("\n");
    }
    return 0;
}
