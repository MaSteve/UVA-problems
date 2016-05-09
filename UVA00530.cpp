#include <cstdio>
//#include <unordered_map>
using namespace std;

/*unordered_map<int, unordered_map<int, int> > comb;

int proc(int n, int m) {
    if (m == 0 || m == n) return 1;
    if (m < 0 || m > n) return 0;
    if (comb[n][m] == 0) comb[n][m] = proc(n-1, m-1) + proc(n-1, m);
    return comb[n][m];
}*/

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && !(n == 0 && m == 0)) {
        //printf("%d\n", proc(n, m)); // TLE
        if (m > n/2) m = n - m;
        unsigned long long comb = 1;
        for (int i = 0; i < m; i++) {
            comb *= n-i;    // comb = (n! / (n-m!)) * (1 / m!)
            comb /= i + 1;
        }
        printf("%llu\n", comb);
    }
    return 0;
}
