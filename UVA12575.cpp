#include <iostream>
#include <cmath>
using namespace std;

double pi = acos(-1);

int main() {
    int T;
    cin >> T;
    while (T--) {
        double A, B;
        double l1, l2, x;
        cin >> A >> B;
        if (A >= 0 && B >= 0) l1 = 0, l2 = pi/2;
        else if (A >= 0 && B < 0) l1 = pi/2, l2 = pi;
        else if (A < 0 && B < 0) l1 = pi, l2 = 3*pi/2;
        else l1 = 3*pi/2, l2 = 2*pi;
        if (B != 0) x = atan(A/B);
        else x = pi/2;
        if (x < 0) x += pi;
        double sol[4];
        sol[0] = A*sin(l1) + B*cos(l1);
        sol[1] = A*sin(x) + B*cos(x);
        sol[2] = A*sin(l2) + B*cos(l2);
        sol[3] = A*sin(x+pi) + B*cos(x+pi);
        if (sol[0] >= sol[1] && sol[0] >= sol[2] && sol[0] >= sol[3]) printf("%.2lf %.2lf\n", l1, sol[0]);
        else if (sol[1] >= sol[0] && sol[1] >= sol[2] && sol[1] >= sol[3]) printf("%.2lf %.2lf\n", x, sol[1]);
        else if (sol[2] >= sol[0] && sol[2] >= sol[1] && sol[2] >= sol[3]) printf("%.2lf %.2lf\n", l2, sol[2]);
        else printf("%.2lf %.2lf\n", x+pi, sol[3]);
    }
    return 0;
}
