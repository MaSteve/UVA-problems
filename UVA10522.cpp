#include <iostream>
#include <cmath>
using namespace std;

const double eps=1e-9;

int main() {
    int n;
    cin >> n;
    while (n) {
        double ha, hb, hc, v;
        cin >> ha >> hb >> hc;
        bool invalid = (ha <= 0 || hb <= 0 || hc <= 0);
        if (!invalid) {
            v = (1/ha + 1/hb + 1/hc)*(-1/ha + 1/hb + 1/hc)*(1/ha - 1/hb + 1/hc)*(1/ha + 1/hb - 1/hc);
            invalid = (v <= eps);
        }
        if (invalid) printf("These are invalid inputs!\n"), n--;
        else printf("%.3lf\n", sqrt(1/v));
    }
    return 0;
}
