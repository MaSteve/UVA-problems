#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

int proc(int n, int m) {
    int k = max(m, n-m);
    double val = 0;
    for (int i = n; i > k; i--) val += log10(i);
    for (int i = n - k; i > 0; i--) val -= log10(i);
    val += 0.0000005; //Magic touch
    return (int) ceil(val);
}

int main() {
    int n, m;
    while (cin >> n >> m) printf("%d\n", proc(n, m));
    return 0;
}
