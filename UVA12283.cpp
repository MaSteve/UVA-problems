#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int dp[101][101], costumes[100];

int proc(int i, int j) {
    if (j < i) return 0;
    if (dp[i][j] == -1) {
        int val = 1 + proc(i, j-1);
        for (int k = i; k < j; k++) {
            if (costumes[k] == costumes[j]) val = min(val, proc(i, k) + proc(k+1, j-1));
        }
        dp[i][j] = val;
    }
    return dp[i][j];
}

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) cin >> costumes[i];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = -1;
        printf("Case %d: %d\n", c, proc(0, N-1));
    }
    return 0;
}
