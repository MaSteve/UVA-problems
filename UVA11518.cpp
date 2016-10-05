#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vi> AdjList;
vector<bool> knocked;

int proc(int k) {
    int tiles = 0;
    queue<int> q;
    q.push(k);
    while (!q.empty()) {
        if (!knocked[q.front()]) {
            knocked[q.front()] = true;
            tiles++;
            for (int i = 0; i < AdjList[q.front()].size(); i++) {
                q.push(AdjList[q.front()][i]);
            }
        }
        q.pop();
    }
    return tiles;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, l;
        cin >> n >> m >> l;
        AdjList.assign(n, vi());
        knocked.assign(n, false);
        for (int i = 0; i < m; i++) {
            int s, d;
            cin >> s >> d;
            AdjList[s-1].push_back(d-1);
        }
        int tiles = 0;
        for (int i = 0; i < l; i++) {
            int k;
            cin >> k;
            tiles += proc(k-1);
        }
        printf("%d\n", tiles);
    }
    return 0;
}
