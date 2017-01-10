#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N;
    int c = 1;
    while (cin >> N && N != 0) {
        long long n = ceil((3 + sqrt(9+8*N))/2);
        printf("Case %d: %lld\n", c, n);
        c++;
    }
    return 0;
}
