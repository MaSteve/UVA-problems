#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

typedef long long ll;
typedef unordered_map<int, ll> uill;

unordered_map<int, uill> map;
ll fact[21];
ll dp[22][22];

ll comb(int n, int m) {
    if (m < 0 || m > n) return 0;
    if (n == m || m == 0) return 1;
    if (!map[n].count(m)) {
        map[n][m] = comb(n-1, m-1) + comb(n-1, m);
    }
    return map[n][m];
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < 21; i++) fact[i] = i*fact[i-1];
    dp[0][0] = 1, dp[1][0] = 0, dp[1][1] = 1;
    for (int i = 2; i < 21; i++) {
        dp[i][0] = fact[i] - 1;
        for (int j = i-1; j >= 2; j--) dp[i][0] -=  dp[j][0]*comb(i, i-j);
        for (int j = 1; j <= i; j++) {
            dp[i][j] = comb(i, j)*dp[i-j][0];
        }
    }
    int N, M;
    while (cin >> N >> M) {
        ll ret = 0;
        for (int i = 0; i <= M; i++) ret += dp[N][i];
        printf("%lld\n", ret);
    }
    return 0;
}
