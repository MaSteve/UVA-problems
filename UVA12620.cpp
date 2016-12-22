#include <iostream>
using namespace std;

int main() {
    int fibs[300];
    unsigned long long sum[300];
    sum[0] = 0;
    sum[1] = 1;
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i < 300; i++) fibs[i] = (fibs[i-1] + fibs[i-2])%100, sum[i] = sum[i-1] + fibs[i];
    int T;
    cin >> T;
    while (T--) {
        unsigned long long N, M;
        cin >> N >> M;
        if (N % 300 == 0) N++;
        printf("%llu\n", ((M/300)-(N/300))*sum[299] + sum[M%300] - sum[(N+299)%300]);
    }
    return 0;
}
