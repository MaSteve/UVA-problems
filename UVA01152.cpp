#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> A, B, C, D, sum;
    unordered_map<int, int> m;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        A.clear(), B.clear(), C.clear(), D.clear(), sum.clear(), m.clear();
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            A.push_back(a), B.push_back(b), C.push_back(c), D.push_back(d);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum1 = A[i] + B[j], sum2 = C[i] + D[j];
                sum.push_back(sum1);
                m[sum2]++;
            }
        }
        int res = 0;
        for (int i = 0; i < sum.size(); i++) {
            res += m[-sum[i]];
        }
        printf("%d\n", res);
        if (t) printf("\n");
    }
    return 0;
}
