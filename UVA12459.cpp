#include <iostream>
using namespace std;

int main() {
    long long fib[81];
    fib[0] = 1, fib[1] = 1;
    for (int i = 2; i < 81; i++) fib[i] = fib[i-1] + fib[i-2];
    int n;
    while (cin >> n && n) {
        printf("%lld\n", fib[n]);
    }
    return 0;
}
