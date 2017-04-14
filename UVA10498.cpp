#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<double> vd;

int n, m;
vector<double> c, b, w, bauxi;
vector<vd> A, B_1;
double z;
double EPS = 1e-9;

void simplex() {
    B_1.assign(m, vd(m, 0));
    for (int i = 0; i < m; i++) B_1[i][i] = 1;
    w.assign(m, 0);
    bauxi.assign(m, 0);

    while (true) {
        /*for (int i = 0; i < m; i++) printf("%f ", w[i]);
        printf("%f\n", z);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                printf("%f ", B_1[i][j]);
            }
            printf("%f\n", b[i]);
        }
        printf("-------------------------------------------------\n");*/

        double maxi = 0;
        int var = -1;
        for (int i = 0; i < n + m; i++) {
            double cauxi = 0;
            for (int j = 0; j < m; j++) {
                cauxi += w[j]*A[j][i];
            }
            cauxi -= c[i];
            if (cauxi > maxi) maxi = cauxi, var = i;
        }
        if (var == -1 || maxi < EPS) break;

        for (int i = 0; i < m; i++) {
            bauxi[i] = 0;
            for (int j = 0; j < m; j++) {
                bauxi[i] += B_1[i][j]*A[j][var];
            }
        }
        double mini;
        int pos = -1;
        bool first = false;
        for (int i = 0; i < m; i++) {
            if (bauxi[i] > EPS) {
                if (first) {
                    double auxi = b[i]/bauxi[i];
                    if (auxi < mini) mini = auxi, pos = i;
                } else mini = b[i]/bauxi[i], pos = i, first = true;
            }
        }
        if (pos == -1) break;

        for (int i = 0; i < m; i++) B_1[pos][i] /= bauxi[pos];
        b[pos] /= bauxi[pos];
        for (int i = 0; i < m; i++) {
            w[i] -= B_1[pos][i]*maxi;
            if (i == pos) continue;
            for (int j = 0; j < m; j++) {
                B_1[i][j] -= B_1[pos][j]*bauxi[i];
            }
            b[i] -= b[pos]*bauxi[i];
        }
        z -= b[pos]*maxi;
    }
}

int main() {
    while (cin >> n >> m) {
        c.assign(n + m, 0);
        for (int i = 0; i < n; i++) cin >> c[i], c[i] = -c[i];
        A.assign(m, vd(n+m, 0));
        b.assign(m, 0);
        z = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cin >> A[i][j];
            A[i][i + n] = 1;
            cin >> b[i];
        }
        simplex();
        printf("Nasa can spend %d taka.\n", (int) ceil(-m*z));
    }
    return 0;
}
