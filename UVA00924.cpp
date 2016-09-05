#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

ii proc(int s, vector<vi> & graph) {
    unordered_set<int> match;
    queue<ii> q;
    q.push(make_pair(s, 0));
    match.insert(s);
    int cday = 0, ccount = 0;
    int boomday = 1, boomsize = 1;
    while (!q.empty()) {
        for (int i = 0; i < graph[q.front().first].size(); i++) {
            if (!match.count(graph[q.front().first][i])) q.push(make_pair(graph[q.front().first][i], q.front().second + 1)), match.insert(graph[q.front().first][i]);
        }
        if (cday != q.front().second) {
            if (ccount > boomsize) boomsize = ccount, boomday = cday;
            cday = q.front().second, ccount = 0;
        }
        ccount++;
        q.pop();
    }
    if (ccount > boomsize) boomsize = ccount, boomday = cday;
    return make_pair(cday? boomday: -1, boomsize);
}

int main() {
    int E;
    cin >> E;
    vector<vi> graph(E, vi());
    for (int i = 0; i < E; i++) {
        int N;
        cin >> N;
        while (N--) {
            int f;
            cin >> f;
            graph[i].push_back(f);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int s;
        cin >> s;
        ii r = proc(s, graph);
        if (r.first >= 0) printf("%d %d\n", r.second, r.first);
        else printf("0\n");
    }
    return 0;
}
