#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    int digits[11];
    while (cin >> n && n != 0) {
        int l = 0;
        int b = 0;
        while (n) {
            digits[l] = n%10;
            if (digits[l] + 1 > b) b = digits[l] + 1;
            n /= 10;
            l++;
        }
        for (; b <= 100; b++) {
            unsigned long long val = 0, pot = 1;
            for (int i = 0; i < l; i++) {
                val += digits[i]*pot;
                pot *= b;
            }
            long long sq = floor(sqrt(val));
            if (val == sq*sq) break;
        }
        printf("%d\n", b);
    }
    return 0;
}
