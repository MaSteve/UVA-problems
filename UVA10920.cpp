#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long S, P;
    while (cin >> S >> P && !(S == 0 && P == 0)) {
        long long val = floor(sqrt(P));
        if (P == val*val) val--;
        long long x, y;
        if (val % 2 == 1) {
            x = val + 1, y = val + 1;
            x -= P - 1 - val*val;
            if (x < 1) y += x - 1, x = 1;
            val++, y++;
        } else {
            y = 1, x = P - val*val;
            if (x > val + 1) y = x - val, x = val + 1;
        }
        x += (S - val - 1)/2, y += (S - val - 1)/2;
        printf("Line = %lld, column = %lld.\n", y, x);
    }
    return 0;
}
