#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long val = 9;
    int cont = 0;
    while (cont != 7) {
        val++;
        long long sq = val*val;
        int sum = 0;
        while (sq) {
            sum += sq%10;
            sq /= 10;
        }
        int auxi = floor(sqrt(sum));
        auxi *= auxi;
        if (auxi == sum) cont++;
        else cont = 0;
    }
    for (long long i = val - 6; i <= val; i++) printf("%lld %lld\n", i, i*i);
    return 0;
}
