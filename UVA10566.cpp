#include <iostream>
#include <cmath>
using namespace std;

double proc(double x, double y, double c) {
    double ini = 0, end = min(x, y), eps = 0.000001;
    while (end - ini > eps) {
        double mid = (ini + end)/2;
        double hx = sqrt(x*x - mid*mid);
        double hy = sqrt(y*y - mid*mid);
        double dx = (mid*c/hx);
        double dy = (mid*c/hy);
        if (dx + dy < mid) ini = mid;
        else if(dx + dy > mid) end = mid;
        else ini = end;
    }
    return ini;
}

int main() {
    double x, y, c;
    while (cin >> x >> y >> c) {
        printf("%.3lf\n", proc(x, y, c));
    }
    return 0;
}
