#include <iostream>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int C;
    cin >> C;
    while (C--) {
        int T, N;
        cin >> T >> N;
        while (T--) {
            int x1, y1, x2, y2, x, y;
            cin >> x1 >> y1 >> x2 >> y2;
            x = x2 - x1, y = y2 - y1;
            if (x < 0) x = -x;
            if (y < 0) y = -y;
            if ((x1 % 2 == y1 % 2 && x2 % 2 == y2 % 2) || (x1 % 2 != y1 % 2 && x2 % 2 != y2 % 2)) {
                if (x1 == x2 && y1 == y2) printf("0\n");
                else if (x == y) printf("1\n");
                else printf("2\n");
            } else printf("no move\n");
        }
    }
    return 0;
}
