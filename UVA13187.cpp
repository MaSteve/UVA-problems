#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long S;
        scanf("%lld", &S);
        printf("%lld\n", ((S + 1)*(S + 1) - 1));
    }
    return 0;
}
