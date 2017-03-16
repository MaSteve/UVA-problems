#include <iostream>
using namespace std;

inline int gauss(int n) {
    return n*(n+1)/2;
}

int main() {
    int n;
    cin >> n;
    for (int c = 1; c <= n; c++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        printf("Case %d: %d\n", c, x2 + gauss(x2 + y2) - gauss(x1 + y1) - x1);
    }
    return 0;
}
