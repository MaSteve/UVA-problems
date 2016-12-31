#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int L;
    string s;
    while (cin >> L && L != 0) {
        cin >> s;
        int d = -1, r = -1, dist = L + 1;
        for (int i = 0; i < L; i++) {
            if (s[i] == 'R') r = i;
            else if (s[i] == 'D') d = i;
            else if (s[i] == 'Z') {
                d = r = i, dist = 0;
                break;
            } else continue;
            if (d >= 0 && r >= 0) dist = min(dist, abs(d - r));
        }
        printf("%d\n", dist);
    }
    return 0;
}
