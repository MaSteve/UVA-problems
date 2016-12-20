#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long N;
        scanf("%lld", &N);
        printf("%lld\n", (N >> 1));
    }
    return 0;
}
