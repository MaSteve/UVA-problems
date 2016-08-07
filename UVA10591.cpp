#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        unordered_set<int> s;
        long long N;
        cin >> N;
        printf("Case #%d: %lld", i, N);
        while (N != 1 && !s.count(N)) {
            s.insert(N);
            long long auxi = 0;
            while (N) {
                auxi += (N%10)*(N%10);
                N/=10;
            }
            N = auxi;
        }
        if (N == 1) printf(" is a Happy number.\n");
        else printf(" is an Unhappy number.\n");
    }
    return 0;
}
