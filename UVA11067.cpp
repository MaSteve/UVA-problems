#include <iostream>
using namespace std;

long long dp[103][103];

int main() {
    int w, h;
    while (cin >> w >> h && !(w == 0 && h == 0)) {
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                dp[j][i] = 0;
            }
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            dp[x][y] = -1;
        }
        dp[w][h] = 1;
        for (int i = w - 1; i >= 0; i--) {
            int x = i, y = h;
            while (y >= 0 && x <= w) {
                if (dp[x][y] == -1) dp[x][y] = 0;
                else {
                    dp[x][y] = dp[x+1][y] + dp[x][y+1];
                }
                x++, y--;
            }
        }
        for (int i = h - 1; i >= 0; i--) {
            int x = 0, y = i;
            while (y >= 0 && x <= w) {
                if (dp[x][y] == -1) dp[x][y] = 0;
                else {
                    dp[x][y] = dp[x+1][y] + dp[x][y+1];
                }
                x++, y--;
            }
        }
        if (dp[0][0] > 1) printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n", dp[0][0]);
        else if (dp[0][0] == 1) printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else if (dp[0][0] == 0) printf("There is no path.\n");
    }
    return 0;
}
