#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int x1ll, y1ll, x1ur, y1ur, x2ll, y2ll, x2ur, y2ur;
        cin >> x1ll >> y1ll >> x1ur >> y1ur >> x2ll >> y2ll >> x2ur >> y2ur;
        int X1, X2, Y1, Y2;
        X1 = max(x1ll, x2ll);
        Y1 = max(y1ll, y2ll);
        X2 = min(x1ur, x2ur);
        Y2 = min(y1ur, y2ur);
        if (X1 < X2 && Y1 < Y2) printf("%d %d %d %d\n", X1, Y1, X2, Y2);
        else printf("No Overlap\n");
        if (N) printf("\n");
    }
    return 0;
}
