#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a != b && b == c) printf("A\n");
        else if (b != a && a == c) printf("B\n");
        else if (c != b && a == b) printf("C\n");
        else printf("*\n");
    }
    return 0;
}
