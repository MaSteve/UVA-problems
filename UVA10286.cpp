#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double l, c = sin(108*(acos(0)/90))/sin(63*(acos(0)/90));
    while (cin >> l) printf("%.10lf\n", l*c);
    return 0;
}
