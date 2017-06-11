#include <iostream>
using namespace std;

int n, k;

int proc(int n, bool plus) {
    if (n < k) return plus? n: 0;
    return (plus? n - (n / k): 0) + proc(n/k, !plus);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        printf("%d\n", proc(n, true));
    }
    return 0;
}
