#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

vector<int> labels;
unordered_map<int, unordered_map<int, unsigned long long> > counts;

int main() {
    int cases = 1, n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        labels.assign(n + 1, 0);
        printf("Case %d:\n", cases++);
        for (int i = 0; i < n; i++) {
            int aux;
            cin >> aux;
            labels[aux]++;
        }
        for (int i = 0; i < m; i++) {
            int r;
            cin >> r;
            counts.clear();
            counts[0][0] = 1;
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k <= r; k++) counts[j][k] = counts[j-1][k];
                for (int k = 0; k <= r; k++) {
                    for (int l = 1; l <= labels[j] && l+k <= r; l++) {
                        counts[j][k+l] += counts[j-1][k];
                    }
                }
            }
            printf("%llu\n", counts[n][r]);
        }
    }
    return 0;
}
