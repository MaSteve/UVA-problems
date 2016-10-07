#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;
vi dfs_num, dfs_low;
vector<bool> apoints;
int counter, n0;

void artpoint(int n, int p) {
    dfs_num[n] = dfs_low[n] = counter++;
    for (int i = 0; i < AdjList[n].size(); i++) {
        if (dfs_num[AdjList[n][i]] == -1) {
            if (n == 0) n0++;
            artpoint(AdjList[n][i], n);
            if (dfs_low[AdjList[n][i]] >= dfs_num[n]) apoints[n] = true;
            else dfs_low[n] = min(dfs_low[n], dfs_low[AdjList[n][i]]);
        } else if (AdjList[n][i] != p) {
            dfs_low[n] = min(dfs_low[n], dfs_num[AdjList[n][i]]);
        }
    }
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        string s;
        AdjList.assign(N, vi());
        while (getline(cin, s) && s != "0") {
            istringstream iss(s);
            int n1, n2;
            iss >> n1;
            while (iss >> n2) {
                AdjList[n1-1].push_back(n2-1);
                AdjList[n2-1].push_back(n1-1);
            }
        }
        n0 = counter = 0;
        apoints.assign(N, false);
        dfs_num.assign(N, -1);
        dfs_low.assign(N, -1);
        artpoint(0, 0);
        int ap = 0;
        apoints[0] = (n0 > 1);
        for (int i = 0; i < N; i++) if (apoints[i]) ap++;
        printf("%d\n", ap);
    }
    return 0;
}
