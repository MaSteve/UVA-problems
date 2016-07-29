#include <iostream>
using namespace std;

int main() {
    int h1, m1, h2, m2;
    while (cin >> h1 >> m1 >> h2 >> m2 && !(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)) {
        m1 += h1*60, m2 += h2*60;
        int r = m2 - m1;
        if (r < 0) r += 1440;
        printf("%d\n", r);
    }
    return 0;
}
