#include <iostream>
using namespace std;

long long pow[32];

long long proc(int K, int A, int B) {
    if (B < A) return 0;
    if (A == 1 && B == (1<<K)) return pow[K];
    else {
        long long ret = 0;
        ret += 2*proc(K-1, A, min((1<<(K-1)), B));
        ret += proc(K-1, max(1, A - (1<<(K-1))), B - (1<<(K-1)));
        return ret;
    }
}

int main() {
    pow[0] = 1;
    for (int i = 1; i < 32; i++) pow[i] = pow[i-1]*3;
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int K, A, B;
        cin >> K >> A >> B;
        printf("Case %d: %lld\n", c, proc(K, A, B));
    }
    return 0;
}
