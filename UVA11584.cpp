#include <iostream>
#include <unordered_map>
using namespace std;

/*typedef unordered_map<int, int> uii;

unordered_map<int, uii> dp;
string s;

int proc(int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (!dp[i].count(j)) {
        bool ok = false;
        if (s[i] == s[j]) {
            if (proc(i + 1, j - 1) <= 1) dp[i][j] = 1, ok = true;
        }
        if (!ok) {
            int mini = 10000;
            for (int k = i; k < j; k++) {
                int sum = proc(i, k) + proc(k + 1, j);
                if (sum < mini) mini = sum;
            }
            dp[i][j] = mini;
        }
    }
    return dp[i][j];
}*/

string s;
int dp[1010][1010];
int v[1010];

int proc(int i) {
    if (i >= s.length()) return 0;
    if (v[i] == -1) {
        int mini = 10000, l = dp[s.length()][i];
        while (l > 1) {
            int val = 1 + proc(i + l);
            if (val < mini) mini = val;
            l = dp[l-1][i];
        }
        int val = 1 + proc(i + 1);
        if (val < mini) mini = val;
        v[i] = mini;
    }
    return v[i];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        //dp.clear();
        cin >> s;
        for (int i = 0; i < s.length(); i++) dp[1][i] = 1, v[i] = -1;
        for (int l = 2; l <= s.length(); l++) {
            for (int i = 0; i < s.length(); i++) {
                if (i + l - 1 >= s.length()) dp[l][i] = dp[l-1][i];
                else {
                    if (s[i] == s[i+l-1] && dp[l-2][i+1] == l-2) dp[l][i] = l; //Palindrome
                    else dp[l][i] = dp[l-1][i];
                }
            }
        }
        printf("%d\n", proc(0));
        //printf("%d\n", proc(0, s.length() - 1));
    }
    return 0;
}
