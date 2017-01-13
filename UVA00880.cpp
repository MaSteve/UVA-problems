#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned long long n;
    while (cin >> n) {
        unsigned long long den = (-1 + floor(sqrt(1+8*n)))/2;
        unsigned long long num = n - (den*(den+1)/2);
        if (num == 0) printf("1/%llu\n", den);
        else printf("%llu/%llu\n", den + 2 - num , num);
    }
    return 0;
}
