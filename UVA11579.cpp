#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps=1e-9;

int main() {
    int T;
    double sides[10002];
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> sides[i];
        sort(sides, sides+N);
        double best = 0, v;
        for (int i = 2; i < N; i++) {
            if (sides[i-2] + sides[i-1] <= sides[i]) continue;
            v = (sides[i] + sides[i-1] + sides[i-2])*(-sides[i] + sides[i-1] + sides[i-2])*(sides[i] - sides[i-1] + sides[i-2])*(sides[i] + sides[i-1] - sides[i-2]);
            v /= 16;
            if (v > best) best = v;
        }
        printf("%.2lf\n", (sqrt(best)));
    }
    return 0;
}
