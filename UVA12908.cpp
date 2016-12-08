#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int S;
    while (cin >> S && S != 0) {
        int n = floor((-1+sqrt(1+8*S))/2);
        while (n*(n+1)/2 - S <= 0) n++;
        printf("%d %d\n", n*(n+1)/2 - S, n);
    }
    return 0;
}
