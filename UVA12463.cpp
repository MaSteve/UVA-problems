#include <iostream>
using namespace std;

int main() {
    long long a, b, c, d, e;
    while (cin >> a >> b >> c >> d >> e &&
        !(a == 0 && b == 0 && c == 0 && d == 0 && e == 0)) {
        printf("%lld\n", a*b*c*d*d*e*e);
    }
    return 0;
}
