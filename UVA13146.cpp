#include <iostream>
using namespace std;

string s1, s2;
int dp[102][102];

int main() {
    int N;
    cin >> N;
    getline(cin, s1);
    while (N--) {
        getline(cin, s1);
        getline(cin, s2);
        for (int i = s1.length(); i >= 0; i--) dp[i][s2.length()] = s1.length() - i;
        for (int j = s2.length(); j >= 0; j--) dp[s1.length()][j] = s2.length() - j;
        for (int i = s1.length()-1; i >= 0; i--) {
            for (int j = s2.length()-1; j >= 0; j--) {
                dp[i][j] = min(dp[i+1][j+1] + (s1[i] == s2[j]? 0: 1), min(dp[i+1][j] + 1, dp[i][j+1] + 1));
            }
        }
        printf("%d\n", dp[0][0]);
    }
    return 0;
}
