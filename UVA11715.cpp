#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t, cases = 1;
    while (cin >> t && t != 0) {
        cout << "Case "<< cases << ": ";
        double v1, v2, v3;
        cin >> v1 >> v2 >> v3;
        if (t == 1) {
            double a = (v2 - v1)/v3;
            double s = v1*v3 + (a*v3*v3)/2;
            printf("%.3f %.3f\n", s, a);
        }
        else if (t == 2) {
            double ti = (v2-v1)/v3;
            double s = v1*ti + (v3*ti*ti)/2;
            printf("%.3f %.3f\n", s, ti);
        }
        else if (t == 3) {
            double ti = (-v1 + sqrt(v1*v1 + 2*v3*v2))/v2;
            double v = v1 + v2*ti;
            printf("%.3f %.3f\n", v, ti);
        }
        else if (t == 4) {
            double ti = (-v1 + sqrt(v1*v1 - 2*v3*v2))/(-v2);
            double u = v1 - v2*ti;
            printf("%.3f %.3f\n", u, ti);
        }
        cases++;
    }
    return 0;
}
