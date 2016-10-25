#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        long long k;
        cin >> k;
        if (k == 0) printf("3\n");
        else {
            if (k < 0) k = -k;
            long long val = (floor(sqrt(1+8*k))-1)/2;
            long long S = (val+1)*val/2;
            while (S < k || S%2 != k%2) {
                val++;
                S = (val+1)*val/2;
            }
            printf("%lld\n", val);
        }
        if (N) printf("\n");
    }
    return 0;
}
