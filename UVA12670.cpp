#include <iostream>
#include <cmath>
using namespace std;

inline long long proc1(long long n) {
    if (n == 0) return 0;
    long long ret = 0;
    while (n > 0) {
        int l = floor(log2(n));
        ret += l*((long long) 1<<(l-1));
        long long p = (long long) 1<<l;
        ret += n - p + 1;
        n -= p;
    }
    return ret;
}

int main() {
    long long A, B;
    while (scanf("%lld %lld", &A, &B) == 2) {
        printf("%llu\n", proc1(B) - proc1(A-1));
    }
    return 0;
}
