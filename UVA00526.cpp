#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
string x, y;
unordered_map<int, unordered_map<int, int> > dp;
unordered_map<int, unordered_map<int, int> > decdp;

int proc(int i, int j) {
    if (i >= N) return M - j;
    if (j >= M) return N - i;
    if (!dp[i].count(j)) {
        if (x[i] == y[j]) {
            dp[i][j] = proc(i+1, j+1);
            decdp[i][j] = 0;
        }
        else {
            int v1 = proc(i+1, j+1);
            int v2 = proc(i+1, j);
            int v3 = proc(i, j+1);
            dp[i][j] = 1 + min(v1, min(v2, v3));
            if (v1 + 1 == dp[i][j]) decdp[i][j] = 1;
            else if (v2 + 1 == dp[i][j]) decdp[i][j] = 2;
            else if (v3 + 1 == dp[i][j]) decdp[i][j] = 3;
        }
    }
    return dp[i][j];
}

int c;

void proc2(int i, int j, int idx) {
    c++;
    if (i >= N) {
        for (; j < M; j++, c++, idx++) printf("%d Insert %d,%c\n", c, idx, y[j]);
        return;
    }
    if (j >= M) {
        for (; i < N; i++, c++) printf("%d Delete %d\n", c, idx);
        return;
    }
    if (decdp[i][j] == 0) {
        c--;
        proc2(i+1, j+1, idx+1);
    } else if (decdp[i][j] == 1) {
        printf("%d Replace %d,%c\n", c, idx, y[j]);
        proc2(i+1, j+1, idx+1);
    } else if (decdp[i][j] == 2) {
        printf("%d Delete %d\n", c, idx);
        proc2(i+1, j, idx);
    } else if (decdp[i][j] == 3) {
        printf("%d Insert %d,%c\n", c, idx, y[j]);
        proc2(i, j+1, idx+1);
    }
}

int main() {
    bool first = false;
    while (getline(cin, x) && getline(cin, y)) {
        N = x.length();
        M = y.length();
        if (first) printf("\n");
        else first = true;
        dp.clear();
        decdp.clear();
        printf("%d\n", proc(0, 0));
        c = 0;
        proc2(0, 0, 1);
    }
    return 0;
}
