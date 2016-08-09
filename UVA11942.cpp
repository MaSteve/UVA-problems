#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    printf("Lumberjacks:\n");
    while (N--) {
        bool or1 = true, or2 = true;
        int prev, act;
        cin >> prev;
        for (int i = 1; i < 10; i++) {
            cin >> act;
            or1 &= (act >= prev);
            or2 &= (act <= prev);
            prev = act;
        }
        if (or1 || or2) printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}
