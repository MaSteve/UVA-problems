#include <iostream>
using namespace std;

int main() {
    int digits[10001];
    digits[0] = 1;
    for (int i = 1; i < 10001; i++) {
        digits[i] = digits[i-1] * i;
        while (digits[i] % 10 == 0) digits[i] /= 10;
        digits[i] %= 100000;
    }
    int n;
    while (cin >> n) {
        printf("%5d -> %d\n", n, digits[n]%10);
    }
    return 0;
}
