#include <cstdio>
using namespace std;

int main() {
    int ini, c1, c2, c3;
    while (scanf("%d %d %d %d", &ini, &c1, &c2, &c3) && !(ini == 0 && c1 == 0 && c2 == 0 && c3 == 0)) {
        int grades = 0;
        grades += c1 > ini? ini + 40 - c1: ini - c1;
        grades += c2 < c1?  c2 + 40 - c1: c2 - c1;
        grades += c3 > c2? c2 + 40 - c3: c2 - c3;
        grades *= 9;
        grades += 1080;
        printf("%d\n", grades);
    }
    return 0;
}
