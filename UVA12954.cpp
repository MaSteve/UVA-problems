#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N, B;
    while (cin >> N >> B) {
        long long d = ceil(sqrt(N*N - B + 1));
        if ((d & 1) != (N & 1)) d++;
        long long sp1 = (N - d)/2 + 1, sp2;
        sp2 = sp1;
        B -= N*N - d*d + 1;
        if (B >= d - 1) {
            sp1 += d - 1;
            B -= d - 1;
            if (B >= d - 1) {
                sp2 += d - 1;
                B -= d - 1;
                if (B >= d - 1) {
                    sp1 -= d - 1;
                    B -= d - 1;
                    sp2 -= B;
                } else sp1 -= B;
            } else sp2 += B;
        } else sp1 += B;
        printf("%lld %lld\n", sp2, sp1);
    }
    return 0;
}
