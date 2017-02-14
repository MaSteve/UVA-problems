#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n > 13 || (n < 0 && n % 2)) printf("Overflow!\n");
        else {
            long long fact = 1;
            for (int i = 1; i <= n; i++) fact *= i;
            if (fact < 10000) printf("Underflow!\n");
            else printf("%lld\n", fact);
        }
    }
    return 0;
}
