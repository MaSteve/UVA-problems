#include <iostream>
using namespace std;

int main() {
    double xl, yl, xr, yr;
    while (cin >> xl >> yl >> xr >> yr) {
        printf("%.6lf\n", ((xr-xl)*(xr-xl) + (yr-yl)*(yr-yl))/6);
    }
    return 0;
}
