#include <iostream>
#include <cmath>
using namespace std;

double pi = 2*acos(0);

int main() {
    double a;
    while (cin >> a) {
        double area = a*a;
        double a1 = 4*area - (2*pi*area/3) - (sqrt(3)*area);
        double a2 = (pi*area/2) - area;
        double a3 = 2*(area - a1 - a2);
        double a4 = area - a1 - a3;
        printf("%.3lf %.3lf %.3lf\n", a4, a3, a1);
    }
    return 0;
}
