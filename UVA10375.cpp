#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int p, q, r, s;
    while (cin >> p >> q >> r >> s) {
        q = min(q, p-q); s = min(s, r-s);
        double val = 1;
        for (int i = 1, j = 1; i <= q || j <= s; i++, j++) { //We have to mix both loops because binomial coefficients are too big, in other words, we can't try to calculate binomial coefficients separately.
            if (i <= q) {
                val *= p-q+i;
                val /= i;
            } if (j <= s) {
                val *= j;
                val /= r-s+j;
            }
        }
        printf("%.5f\n", val);
    }
    return 0;
}
