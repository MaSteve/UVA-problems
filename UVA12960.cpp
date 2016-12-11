#include <iostream>
#include <utility>
#include <unordered_set>
using namespace std;

typedef pair<int, int> ii;

ii dp[2001][2001];
unordered_set<int> sp;
string s;

int main() {
    while (cin >> s) {
        sp.clear();
        int val, auxi;
        cin >> val;
        for (int i = 0; i < val; i++) {
            cin >> auxi;
            sp.insert(auxi-1);
        }
        for (int i = 0; i < s.length(); i++) {
            dp[i][i].first = sp.count(i)? 1: 0;
            dp[i][i].second = 1;
        }
        for (int i = 1; i < s.length(); i++) {
            for (int j = 0; j + i < s.length(); j++) {
                dp[j][j+i] = max(dp[j+1][j+i], dp[j][j+i-1]);
                if (s[j] == s[j+i]) {
                    ii auxi;
                    auxi.first = (sp.count(j)? 1: 0) + (sp.count(j+i)? 1: 0) + dp[j+1][j+i-1].first;
                    auxi.second = 2 + dp[j+1][j+i-1].second;
                    dp[j][j+i] = max(dp[j][j+i], auxi);
                }
            }
        }
        printf("%d\n", dp[0][s.length()-1].second);
    }
    return 0;
}
