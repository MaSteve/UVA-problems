#include <iostream>
using namespace std;

int main() {
    unsigned long long N;
    while (cin >> N) {
        unsigned long long s = N/2;
        s = (N*(N+1)/2) - (s*(s+1));
        printf("%llu\n", 3*(2*s - 3));
    }
    return 0;
}
