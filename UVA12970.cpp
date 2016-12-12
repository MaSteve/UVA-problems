#include <iostream>
using namespace std;

unsigned long long GCD(unsigned long long a, unsigned long long b) {
    if (b == 0) return a;
    else return GCD(b, a%b);
}

int main() {
    unsigned long long v1, d1, v2, d2;
    int c = 1;
    while (cin >> v1 >> d1 >> v2 >> d2 && !(v1 == 0 && d1 == 0 && v2 == 0 && d2 == 0)) {
        printf("Case #%d: ", c);
        if ((v1*d2) > (v2*d1)) printf("You owe me a beer!\n");
        else printf("No beer for the captain.\n");
        unsigned long long num = (v1*d2) + (v2*d1), den = 2*v1*v2;
        unsigned long long gcd = GCD(max(num, den), min(num, den));
        num /= gcd, den /= gcd;
        printf("Avg. arrival time: %llu", num);
        if (den == 1) printf("\n");
        else printf("/%llu\n", den);
        c++;
    }
    return 0;
}
