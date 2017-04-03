#include <iostream>
using namespace std;

int dp[71][71][71];
bool mask[71][71][71];

int F(int N, int T, int P) {
    if (T < P) return 0;
    if (N == 1) return 1;
    if (!mask[N][T][P]) {
        for (int i = P; i < T; i++)
            dp[N][T][P] += F(N-1, T-i, P);
        mask[N][T][P] = true;
    }
    return dp[N][T][P];
}

int main() {
    int K, N, T, P;
    cin >> K;
    while (cin >> N >> T >> P) {
        printf("%d\n", F(N, T, P));
    }
    return 0;
}
