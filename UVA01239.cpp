#include <iostream>
using namespace std;

string s;
int k, DP[1002][1002];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s >> k;
        int l = 1;
        for (int i = 0; i < s.length(); i++) DP[i][i] = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            DP[i][i+1] = s[i] == s[i+1]? 0: 1;
            if (DP[i][i+1] <= k) l = 2;
        }
        for (int j = 2; j < s.length(); j++) {
            for (int i = 0; i + j < s.length(); i++) {
                DP[i][i+j] = DP[i+1][i+j-1] + (s[i] == s[i+j]? 0: 1);
                if (DP[i][i+j] <= k) l = max(l, j+1);
            }
        }
        printf("%d\n", l);
    }
    return 0;
}
