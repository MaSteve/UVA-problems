#include <iostream>
using namespace std;

long long fib[51];

int main() {
    fib[1] = 1, fib[2] = 2;
    for (int i = 3; i < 51; i++) fib[i] = fib[i-1] + fib[i-2];
    int l;
    while (cin >> l && l != 0) {
        printf("%lld\n", fib[l]);
    }
    return 0;
}
