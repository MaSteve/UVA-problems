#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        printf("Case %d: ", i);
        if (a < b + c && b < a + c && c < a + b && a > 0 && b > 0 && c > 0) {
            if (a == b && b == c) printf("Equilateral\n");
            else if (a != b && a != c && b != c) printf("Scalene\n");
            else printf("Isosceles\n");
        } else printf("Invalid\n");
    }
    return 0;
}
