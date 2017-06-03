#include <iostream>
using namespace std;

long long proc(long long n) {
    if (n <= 0) return 0;
    long long ret = 0;
    ret += 45 * (n / 10);
    ret += (n % 10 + 1) * (n % 10) / 2;
    ret += proc(n/10);
    return ret;
}

int main() {
    long long p, q;
    while (cin >> p >> q && !(p < 0 && q < 0)) {
        printf("%lld\n", proc(q) - proc(p - 1));
    }
    return 0;
}
