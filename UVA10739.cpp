#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

string s;
unordered_map<int, unordered_map<int, int> > dp;

int proc(int i, int j) {
    if (i >= j) return 0;
    if (!dp[i].count(j)) {
        if (s[i] == s[j]) dp[i][j] = proc(i+1, j-1);
        else dp[i][j] = min(proc(i+1, j) + 1, min (proc(i, j-1) + 1, proc(i+1, j-1) + 1));
    } return dp[i][j];
}

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> s;
        dp.clear();
        printf("Case %d: %d\n", c, proc(0, s.length() - 1));
    }
    return 0;
}
