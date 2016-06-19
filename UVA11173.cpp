#include <iostream>
#include <cmath>
using namespace std;

int gray(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    int l = floor(log2(k));
    int p = (1 << (l+1)) - k - 1;
    return gray(p) + (1<<l);
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n, k;
        cin >> n >> k;
        printf("%d\n", gray(k));
    }
    return 0;
}
