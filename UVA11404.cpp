#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int dp[1001][1001];
bool mask[1001][1001];
string dp2[1001][1001];

void proc() {
    for (int i = 0; i < s.length(); i++) dp[i][i] = 1, mask[i][i] = false;
    for (int i = 1; i < s.length(); i++) {
        for (int j = 0; j < s.length() - i; j++) {
            mask[j+i][j] = false;
            if (s[j] == s[j+i]) dp[j+i][j] = 2 + dp[j+i-1][j+1];
            else dp[j+i][j] = max(dp[j+i-1][j], dp[j+i][j+1]);
        }
    }
}

string proc2(int fst, int snd) {
    if (snd < fst) return "";
    if (fst == snd) return s.substr(fst, 1);
    if (!mask[snd][fst]) {
        mask[snd][fst] = true;
        if (s[fst] == s[snd]) dp2[snd][fst] = s[fst] + proc2(fst+1, snd-1) + s[fst];
        else {
            if (dp[snd-1][fst] == dp[snd][fst+1]) dp2[snd][fst] = min(proc2(fst+1, snd), proc2(fst, snd-1));
            else if (dp[snd-1][fst] > dp[snd][fst+1]) dp2[snd][fst] = proc2(fst, snd-1);
            else dp2[snd][fst] = proc2(fst+1, snd);
        }
    }
    return dp2[snd][fst];
}

int main() {
    while (cin >> s) {
        proc();
        printf("%s\n", proc2(0, s.length()-1).c_str());
    }
    return 0;
}
