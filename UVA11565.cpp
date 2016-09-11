#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int A, B, C;
        cin >> A >> B >> C;
        bool ok = false;
        for (int x = -100; x <= 100 && !ok; x++) {
            for (int y = -100; y <= 100 && x*x <= C && !ok; y++) {
                for (int z = -100; z <= 100 && x != y && x*x + y*y <= C && !ok; z++) {
                    if (x + y + z == A && x*y*z == B && x*x + y*y + z*z == C && x != z && y != z) {
                        printf("%d %d %d\n", x, y, z);
                        ok = true;
                    }
                }
            }
        }
        if (!ok) printf("No solution.\n");
    }
    return 0;
}
