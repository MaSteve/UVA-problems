#include <iostream>
using namespace std;

long long dp[41];

int main() {
    dp[0] = 1, dp[1] = 1, dp[2] = 5;
    for (int i = 3; i < 41; i++) {
        dp[i] = dp[i-1] + 4*dp[i-2] + 2*dp[i-3];
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        printf("%lld\n", dp[n]);
    }
    return 0;
}
