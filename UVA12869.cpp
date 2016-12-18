#include <iostream>
using namespace std;

int main() {
    long long l, h;
    while (cin >> l >> h && !(l == 0 && h == 0)) {
        printf("%lld\n", (h/5) - (l/5) + 1);
    }
    return 0;
}
