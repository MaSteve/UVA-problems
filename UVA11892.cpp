#include <iostream>
using namespace std;

int dp[20000][20000];

int proc(int eq1, int neq1, bool forced) {
    if (eq1 < 0 ||  neq1 < 0) return 0;
    if (eq1 + neq1 <= 1) return 1;
    if (forced) return proc(eq1 - 1, neq1, false) == 1? -1: 1;
    if (dp[eq1][neq1] == 0) {
        if (proc(eq1 - 1, neq1, false) == -1 ||
            proc(eq1 + 1, neq1 - 1, true) == -1 ||
            proc(eq1, neq1 - 1, false) == -1)
            dp[eq1][neq1] = 1;
        else dp[eq1][neq1] = -1;
    }
    return dp[eq1][neq1];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int eq1 = 0, neq1 = 0;
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            if (val == 1) eq1++;
            else neq1++;
        }
        if (proc(eq1, neq1, false) == 1) printf("poopi\n");
        else printf("piloop\n");
    }
    return 0;
}
