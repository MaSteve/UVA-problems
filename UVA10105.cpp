#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<int, unordered_map<int, long long> > comb;
long long proc(int n, int m) {
    if (m == 0 || m == n) return 1;
    if (m < 0 || m > n) return 0;
    if (comb[n][m] == 0) comb[n][m] = proc(n-1, m-1) + proc(n-1, m);
    return comb[n][m];
}

int main() {
    int N, K;
    while (cin >> N >> K) {
        long long coef = 1;
        for (int i = 0; i < K; i++) {
            int var;
            cin >> var;
            coef *= proc(N, var);
            N -= var;
        }
        cout << coef << endl;
    }
    return 0;
}
