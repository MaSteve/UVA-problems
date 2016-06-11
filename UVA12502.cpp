#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double x, y, z;
        scanf("%lf %lf %lf", &x, &y, &z);
        printf("%d\n", int(z*(2*x - y)/(x+y)));
    }
    return 0;
}
