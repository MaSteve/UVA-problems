#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        long long A, B;
        cin >> A >> B;
        long long aux = (~0ll)-(~(A^B));
        int count = 0;
        while (aux) {
            aux >>= 1;
            count++;
        }
        long long mask = (1ll << count) - 1;
        printf("Case %d: %lld %lld\n", c, A | B | mask, A & B & (~mask));
    }
    return 0;
}
