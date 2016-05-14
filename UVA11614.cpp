#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        unsigned long long n;
        scanf("%llu", &n);
        unsigned long long r = (sqrt(1+8*n) - 1)/2;
        printf("%llu\n", r);
    }
    return 0;
}
