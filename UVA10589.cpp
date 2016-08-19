#include <iostream>
using namespace std;

int main() {
    int N;
    double a;
    while (cin >> N >> a && N != 0) {
        int M = 0;
        for (int i = 0; i < N; i++) {
            double x, y;
            cin >> x >> y;
            if (x*x + y*y <= a*a && (x-a)*(x-a) + y*y <= a*a &&
                x*x + (y-a)*(y-a) <= a*a && (x-a)*(x-a) + (y-a)*(y-a) <= a*a) M++;
        }
        printf("%.5lf\n", (M*a*a)/N);
    }
    return 0;
}
