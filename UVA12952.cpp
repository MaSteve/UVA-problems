#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int c1, c2;
    while (cin >> c1 >> c2) printf("%d\n", max(c1, c2));
    return 0;
}
