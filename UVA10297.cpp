#include <iostream>
#include <cmath>
using namespace std;

double PI = 2*acos(0);

int main() {
    double D, V;
    while (cin >> D >> V && !(D == 0 && V == 0)) {
        double d = cbrt(D*D*D - (6*V/PI));
        printf("%.3lf\n", d);
    }
    return 0;
}
