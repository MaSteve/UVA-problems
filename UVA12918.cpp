#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        printf("%lld\n", ((m-n)*n) + n*(n-1)/2);
    }
    return 0;
}
