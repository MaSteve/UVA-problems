#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, k;
        cin >> n >> k;
        long long limit = pow(10, n) - 1;
        unordered_set<long long> s;
        long long maxi = k;
        long long val = k;
        do {
            s.insert(val);
            if (val > maxi) maxi = val;
            val = val*val;
            while (val > limit) val /= 10;
        } while (!s.count(val));
        printf("%lld\n", maxi);
    }
    return 0;
}
