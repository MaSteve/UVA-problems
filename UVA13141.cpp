#include <iostream>
using namespace std;

int main() {
    long long fib[86];
    fib[1] = fib[2] = 1;
    for (int i = 3; i < 86; i++) fib[i] = fib[i-1] + fib[i-2];
    int n;
    while (cin >> n && n != 0) {
        printf("%lld\n", fib[n]);
    }
    return 0;
}
