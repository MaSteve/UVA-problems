#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int p1, p2, p3, first, second, count = 0;
        cin >> p1 >> p2;
        first = p1;
        p3 = p2;
        second = p2;
        for (int i = 2; i < n; i++) {
            cin >> p3;
            if ((p2 > p1 && p2 > p3) || (p2 < p1 && p2 < p3)) count++;
            p1 = p2;
            p2 = p3;
        }
        if ((p3 > p1 && p3 > first) || (p3 < p1 && p3 < first)) count++;
        if ((first > second && first > p3) || (first < second && first < p3)) count++;
        printf("%d\n", count);
    }
    return 0;
}
