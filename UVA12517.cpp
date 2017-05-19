#include <iostream>
#include <cmath>
using namespace std;

long long sum(long long n) {
    long long ret = 0;
    while (n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

long long proc(long long n) {
    if (n <= 0) return 0;
    long long ret = 0;
    ret += 45 * (n / 10) + ((n % 10 + 1) * (n % 10) / 2);
    ret += 10 * proc(n / 10 - 1) + (n % 10 + 1) * sum(n / 10);
    return ret;
}

int main() {
    long long M, N;
    while (cin >> M >> N && !(N == 0 && M == 0)) {
        printf("%lld\n", proc(N) - proc(M - 1));
    }
    return 0;
}
