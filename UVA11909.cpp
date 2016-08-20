#include <iostream>
#include <cmath>
using namespace std;

double PI = 2*acos(0);

int main() {
    double l, w, h, th;
    while (cin >> l >> w >> h >> th) {
        double d, v, H = sqrt((l*l) + (h*h));
        if (((PI*th)/180) <= asin(h/H)) {
            th = 90 - th;
            d = l/tan((PI*th)/180);
            v = (h*l - ((d*l)/2))*w;
        } else {
            d = h/tan((PI*th)/180);
            v = ((d*h)/2)*w;
        }
        printf("%.3lf mL\n", v);
    }
    return 0;
}
