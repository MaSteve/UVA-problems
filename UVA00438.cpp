#include <iostream>
#include <cmath>
using namespace std;

double pi = 2*acos(0);

int main() {
    double x1, y1, x2, y2, x3, y3;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        double px1 = (x1 + x2)/2, py1 = (y1 + y2)/2,
        px2 = (x1 + x3)/2, py2 = (y1 + y3)/2, sx = 0, sy = 0,
        a = (x2-x1)/(y1-y2), c = (x3-x1)/(y1-y3),
        b = py1 - a*px1, d = py2 - c*px2;
        if (y1 == y2) {
            sx = px1, sy = c*sx + d;
        } else if (y1 == y3) {
            sx = px2, sy = a*sx + b;;
        } else {
            sx = (b-d)/(c-a), sy = a*sx + b;
        }
        printf("%.2lf\n", 2*pi*sqrt((sx - x1)*(sx - x1) + (sy - y1)*(sy - y1)));
    }
    return 0;
}
