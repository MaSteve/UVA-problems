#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<iii> v;
vector<bool> sol;
unordered_map<int, unordered_map<int, ii> > dp;

int proc(int p, int S, int W, bool def) {
    int D = 100000*S + W;
    if (p >= v.size()) return 0;
    if (!(dp.count(p) && dp[p].count(D))) {
        int val1 = proc(p+1, S, W, false), val2 = -2;
        if (S > v[p].second.first && W < v[p].first) val2 = proc(p+1, v[p].second.first, v[p].first, false);
        if (val1 > val2+1) {
            dp[p][D].first = val1;
            dp[p][D].second = 0;
        } else {
            dp[p][D].first = val2 + 1;
            dp[p][D].second = 1;
        }
    }
    if (def) {
        sol[p] = dp[p][D].second;
        if (!dp[p][D].second) {
            proc(p+1, S, W, true);
        } else {
            proc(p+1, v[p].second.first, v[p].first, true);
        }
    }
    return dp[p][D].first;
}

int main() {
    int W, S, c = 0;
    while (cin >> W >> S) {
        v.push_back(iii(W, ii(S, c)));
        c++;
    }
    sort(v.begin(), v.end());
    sol.assign(v.size(), false);
    printf("%d\n", proc(0, 100000, 0, true));
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i]) printf("%d\n", v[i].second.second+1);
    }
    return 0;
}
