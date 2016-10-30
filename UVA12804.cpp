#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef pair<char, int> ci;
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<ci> vect;

vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC, L, acum, warn;

void tarjanSCC(int u) {
    if (dfs_num[u] == -1) acum++;
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = 1;
    int next[2] = {-1, -1};
    if (u < L) {
        if (vect[u].first == 'A') next[0] = u + 1;
        else if (vect[u].first == 'J') next[0] = vect[u].second;
        else if (vect[u].first == 'C') next[0] = u + 1, next[1] = vect[u].second;
    }
    for (int j = 0; j < 2; j++) {
        int v = next[j];
        if (v == -1) continue;
        if (v == u) warn = 1;
        if (dfs_num[v] == -1)
            tarjanSCC(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        numSCC++;
        while (true) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if (u == v) break;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> L;
        vect.assign(L, ci());
        for (int i = 0; i < L; i++) {
            cin >> vect[i].first;
            if (vect[i].first != 'A') cin >> vect[i].second, vect[i].second--;
        }
        dfs_num.assign(L+1, -1); dfs_low.assign(L+1, 0); visited.assign(L+1, 0);
        dfsNumberCounter = numSCC = acum = warn = 0;
        tarjanSCC(0);
        if (dfs_num[L] == -1) printf("NEVER\n");
        else if (numSCC != acum || warn) printf("SOMETIMES\n");
        else printf("ALWAYS\n");
    }
    return 0;
}
