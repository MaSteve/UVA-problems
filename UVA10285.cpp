#include <iostream>
using namespace std;

int H[101][101];
int dp[101][101];
int R, C;

inline bool limits(int i, int j) {
    return i >= 0 && i < R && j >= 0 && j < C;
}

int proc(int i, int j) {
    if (dp[i][j] == -1) {
        dp[i][j] = 0;
        if (limits(i-1, j) && H[i-1][j] < H[i][j]) dp[i][j] = max(dp[i][j], proc(i-1, j) + 1);
        if (limits(i+1, j) && H[i+1][j] < H[i][j]) dp[i][j] = max(dp[i][j], proc(i+1, j) + 1);
        if (limits(i, j-1) && H[i][j-1] < H[i][j]) dp[i][j] = max(dp[i][j], proc(i, j-1) + 1);
        if (limits(i, j+1) && H[i][j+1] < H[i][j]) dp[i][j] = max(dp[i][j], proc(i, j+1) + 1);
    }
    return dp[i][j];
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> H[i][j];
                dp[i][j] = -1;
            }
        }
        int sol = -1;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                sol = max(sol, proc(i, j));
        printf("%s: %d\n", s.c_str(), sol + 1);
    }
    return 0;
}
