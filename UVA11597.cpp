#include <iostream>
using namespace std;

int main() {
    int n, c = 1;
    while (cin >> n && n != 0) {
        printf("Case %d: %d\n", c++, n/2);
    }
    return 0;
}
