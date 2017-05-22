#include <iostream>
using namespace std;

string s;
int dp[260][260];
bool mask[260][260];

void proc() {
    for (int i = 0; i < s.length(); i++) dp[i][i] = 1, mask[i][i] = false;
    for (int i = 0; i < s.length() - 1; i++) dp[i][i+1] = s[i] == s[i+1]? 2: 0, mask[i][i+1] = false;
    for (int l = 2; l < s.length(); l++) {
        for (int i = 0; i + l < s.length(); i++) {
            dp[i][i + l] = s[i] == s[i+l] && dp[i+1][i + l - 1]? dp[i+1][i + l - 1] + 2: 0;
            mask[i][i + l] = false;
        }
    }
}

bool cmp(int p1, int p2, int l) {
    for (int i = 0; i <= l; i++) {
        if (s[p1 + i] != s[p2 + i]) return false;
    }
    return true;
}

bool check(int i, int l) {
    if (l <= 0) return true;
    if (mask[i][i+l] || mask[i][i+l-1] || mask[i+1][i+l-1]) return false;
    else return check(i+1, l-2);
}

bool proc2() {
    int pal1 = -1, len = 0;
    for (int l = 2; l < s.length(); l++) {
        int first = -1;
        for (int i = 0; i + l < s.length(); i++) {
            if (dp[i][i+l]) {
                if (first == -1) {
                    first = i;
                    if (pal1 == -1) pal1 = i, len = l;
                    else if (check(i, l)) return true;
                    mask[i][i+l] = true;
                }
                else {
                    if (!cmp(first, i, l)) return true;
                    mask[i][i+l] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    while (cin >> s) {
        proc();
        if (proc2()) printf("%s\n", s.c_str());
    }
    return 0;
}
