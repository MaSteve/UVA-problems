#include <cstdio>
#include <cmath>
using namespace std;

const double pi = 2*asin(1);

int main() {
    double a, b, v, A, s;
    while (scanf("%lf %lf %lf %lf %lf", &a, &b, &v, &A, &s) && !(a == 0 && b == 0 && v == 0 && A == 0 && s == 0)) {
        double d = (v*s)/2;
        int x = floor((d*cos(pi*A/180) - a/2)/a);
        if (x >= 0) x += 1;
        else x = 0;
        int y = floor((d*sin(pi*A/180) - b/2)/b);
        if (y >= 0) y += 1;
        else y = 0;
        printf("%d %d\n", x, y);
    }
    return 0;
}
