#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

#define MAGIC_NUMBER 3003

typedef unsigned long long llu;

int proc(llu a, llu b, int mod) {
    if (b == 0) return 1;
    int pos = proc(a, b / 2, mod);
    pos *= pos;
    pos %= mod;
    if (b % 2) pos *= a, pos %= mod;
    return pos;
}

int main() {
    int T, fib[MAGIC_NUMBER];
    cin >> T;
    while (T--) {
        llu a, b;
        int n;
        cin >> a >> b >> n;
        if (n == 1) printf("0\n");
        else  {
            fib[0] = 0, fib[1] = 1;
            int i = 2;
            for (; i < MAGIC_NUMBER; i++) {
                fib[i] = (fib[i-1] + fib[i-2]) % n;
                if (fib[i] == fib[1] && fib[i-1] == fib[0]) break;
            }
            a %= i-1;
            int pos = proc(a, b, i - 1);
            printf("%d\n", fib[pos]);
        }
    }
    return 0;
}
