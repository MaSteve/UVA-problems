#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b && !(a == -1 && b == -1)) {
        int c1 = max(a, b) - min(a, b), c2 = min(a, b) + 100 - max(a, b);
        printf("%d\n", min(c1, c2));
    }
    return 0;
}
