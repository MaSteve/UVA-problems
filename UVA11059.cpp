#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, c = 1;
    long long S[20];
    while (cin >> N) {
        long long maxi = 0;
        for (int i = 0; i < N; i++) cin >> S[i], maxi = max(maxi, S[i]);
        for (int i = 0; i < N; i++) {
            long long prod = S[i];
            for (int j = i+1; j < N; j++) {
                prod *= S[j];
                if (prod > maxi) maxi = prod;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", c, maxi);
        c++;
    }
    return 0;
}
