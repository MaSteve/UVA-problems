#include <iostream>
using namespace std;

int main() {
    int n;
    int digits[10];
    while (cin >> n) {
        for (int i = 0; i < 10; i++) {
            digits[i] = 0;
        }
        while (n) {
            digits[n%10]++;
            n /= 10;
        }
        long long a = 0;
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < digits[i]; j++) {
                a *= 10;
                a += i;
            }
        }
        long long b = 0;
        for (int i = 1; i < 10; i++) {
            if (digits[i]) {
                b = i, digits[i]--;
                break;
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < digits[i]; j++) {
                b *= 10;
                b += i;
            }
        }
        printf("%lld - %lld = %lld = 9 * %lld\n", a, b, a - b, (a - b)/9);
    }
    return 0;
}
