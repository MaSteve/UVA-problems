#include <iostream>
#include <cmath>
using namespace std;

long double pi = 2*acos(0);

int main() {
    long double d, theta, r = 6440;
    string s;
    while (cin >> d >> theta >> s) {
        d += r;
        theta = fabs(theta);
        if (s == "min") theta /= 60;
        theta = 2*pi*theta / 360;
        theta = theta - floor(theta/(2*pi))*2*pi;
        if (theta > pi) theta = 2*pi - theta;
        printf("%.6Lf ", theta*d);
        printf("%.6Lf\n", sqrt(2*d*d - 2*d*d*cos(theta)));
    }
    return 0;
}
