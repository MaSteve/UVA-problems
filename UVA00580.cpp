#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;

unordered_map<int, ll> dp;

ll proc(int N) {
    if (!dp.count(N)) {
        dp[N] = (1<<(N-3)) + proc(N - 1) + proc(N - 2) + proc(N - 3);
    }
    return dp[N];
}

int main() {
    int N;
    dp[0] = dp[1] = dp[2] = 0, dp[3] = 1;
    while (cin >> N && N) {
        printf("%lld\n", proc(N));
    }
    return 0;
}
