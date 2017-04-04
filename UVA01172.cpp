#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef unordered_map<int, ii> uiii;

vector<si> v1, v2;
unordered_map<int, uiii> dp;

ii proc(int c1, int c2) {
    if (c1 >= v1.size() || c2 >= v2.size()) return ii(0, 0);
    if (!dp[c1].count(c2)) {
        ii sol = ii(0, 0);
        if (v1[c1].first == v2[c2].first) {
            ii prev = proc(c1+1, c2+1);
            prev.first += v1[c1].second + v2[c2].second;
            prev.second--;
            sol = prev;
        }
        sol = max(sol, proc(c1+1, c2));
        sol = max(sol, proc(c1, c2+1));
        dp[c1][c2] = sol;
    }
    return dp[c1][c2];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        v1.assign(N, si());
        dp.clear();
        for (int i = 0; i < N; i++) {
            string name, os;
            int val;
            cin >> name >> os >> val;
            v1[i] = si(os, val);
        }
        cin >> N;
        v2.assign(N, si());
        for (int i = 0; i < N; i++) {
            string name, os;
            int val;
            cin >> name >> os >> val;
            v2[i] = si(os, val);
        }
        ii sol = proc(0, 0);
        printf("%d %d\n", sol.first, -sol.second);
    }
    return 0;
}
