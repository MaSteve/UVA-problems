#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;

int proc(int n, int k) {
    if (n <= 1) return 0;
    if (!m[(n*1000)+k]) {
        int mini = 1000000000;
        for (int i = 1; i <= n; i++) {
            int auxi = proc(i-1, k) + proc(n-i, k+i) + (k + i)*n;
            if (auxi < mini) mini = auxi;
        }
        m[(n*1000)+k] = mini;
    }
    return m[(n*1000)+k];
}

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int n, k;
        cin >> n >> k;
        printf("Case %d: %d\n", c, proc(n, k));
    }
    return 0;
}
