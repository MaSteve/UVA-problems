#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
string x, y;
unordered_map<int, unordered_map<int, int> > dp;

int proc(int i, int j) {
    if (i >= N) return M - j;
    if (j >= M) return N - i;
    if (!dp[i].count(j)) {
        if (x[i] == y[j]) dp[i][j] = proc(i+1, j+1);
        else dp[i][j] = 1 + min(proc(i+1, j+1), min(proc(i+1, j), proc(i, j+1)));
    }
    return dp[i][j];
}

int main() {
    while (cin >> N >> x >> M >> y) {
        dp.clear();
        printf("%d\n", proc(0, 0));
    }
    return 0;
}
