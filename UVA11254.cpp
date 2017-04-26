#include <iostream>
#include <cmath>
using namespace std;

unsigned long long inv(unsigned long long N) {
    return ceil((sqrt(8*N + 1) - 1)/2);
}

/*unsigned long long gauss(unsigned long long N) {
    return (N+1)*N/2;
}

void proc(unsigned long long N) {
    unsigned long long low = 0, top;
    while (true) {
        top = inv(N + gauss(low));
        if (N + gauss(low) == gauss(top)) {
            printf("%lld = %lld + ... + %lld\n", N, low+1, top);
            break;
        }
        printf("T%lld: %lld %lld %lld\n", N, low, top, gauss(top) - gauss(low));
        low = inv(gauss(top) - N);
        printf("Q%lld: %lld %lld %lld\n", N, low, top, gauss(top) - gauss(low));
    }
}*/

int main() {
    unsigned long long N;
    while (cin >> N && N != -1) {
        //proc(N);
        int sol = 1;
        for (int i = 2; i <= inv(N); i++) {
            if (i % 2 == 1) {
                if (N % i == 0) sol = i;
            } else {
                if (N % i == i / 2) sol = i;
            }
        }
        long long low = N / sol - sol / 2, top = N / sol + sol / 2;
        if (sol % 2 == 0) low++;
        printf("%lld = %lld + ... + %lld\n", N, low, top);
    }
    return 0;
}
