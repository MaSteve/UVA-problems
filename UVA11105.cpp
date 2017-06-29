#include <iostream>
#include <algorithm>
using namespace std;

int H[1000010], N = 0;
int Type[1000010];
int semi[1000010], M = 0;

void sieve() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < i && H[j]*H[j] <= H[i]; j++) {
            if (H[i]%H[j] == 0) {
                int val = H[i]/H[j];
                val--; val /= 4;
                if (Type[val] == 0) {
                    Type[i] = 1;
                    semi[M] = H[i];
                    M++;
                }
                else Type[i] = 2;
                break;
            }
        }
    }
}

int main() {
    for (int i = 1; i < 1000010; i += 4) {
        H[N] = i;
        N++;
    }
    sieve();
    int h;
    while (cin >> h && h != 0) {
        printf("%d %ld\n", h, upper_bound(semi, semi+M, h) - semi);
    }
    return 0;
}
