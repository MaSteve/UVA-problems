#include <iostream>
#include <cmath>
using namespace std;

double PI = 2*acos(0);

int main() {
    int N;
    cin >> N;
    while (N--) {
        double D, L;
        cin >> D >> L;
        D /= 2; L /= 2;
        double b = sqrt(L*L - D*D);
        printf("%.3lf\n", PI*b*L);
    }
    return 0;
}
