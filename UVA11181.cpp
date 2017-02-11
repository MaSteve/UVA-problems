#include <iostream>
using namespace std;

double P[20];
bool mask[20];
int N, r;

double proc(int ri, int pos) {
    if (ri < 0) return 0.0;
    if (pos >= N) {
        if (ri == 0) return 1.0;
        else return 0.0;
    }
    if (ri == 0) {
        double p = 1.0;
        for (int i = pos; i < N; i++) {
            if (!mask[i]) p *= (1.0 - P[i]);
        }
        return p;
    }
    else if (ri != 0) {
        if (mask[pos]) return proc(ri, pos + 1);
        double p = proc(ri, pos + 1)*(1.0 - P[pos]) +
            proc(ri - 1, pos + 1)*(P[pos]);
        return p;
    }
    return 0.0;
}

int main() {
    int c = 1;
    while (cin >> N >> r && !(N == 0 && r == 0)) {
        for (int i = 0; i < N; i++) {
            cin >> P[i];
            mask[i] = false;
        }
        printf("Case %d:\n", c++);
        double PB = proc(r, 0);
        for (int i = 0; i < N; i++) {
            mask[i] = true;
            double PA_B = (proc(r - 1, 0)*P[i]) / PB;
            mask[i] = false;
            printf("%.6lf\n", PA_B);
        }
    }
    return 0;
}
