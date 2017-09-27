#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, t, m;
        cin >> n >> t >> m;
        queue<ii> left, right;
        for (int i = 0; i < m; i++) {
            int val;
            string s;
            cin >> val >> s;
            if (s == "left") left.push(ii(i, val));
            else right.push(ii(i, val));
        }
        int site = 0, tc = 0;
        vector<ii> v;
        while (!(left.empty() && right.empty())) {
            int count = 0;
            bool move = false;
            if (site == 0) {
                while (!left.empty() && count < n && left.front().second <= tc) {
                    ii val = left.front();
                    left.pop();
                    val.second = tc + t;
                    v.push_back(val);
                    move = true;
                    count++;
                }
                if (move) {
                    tc += t;
                    site = 1;
                }
            } else if (site == 1) {
                while (!right.empty() && count < n && right.front().second <= tc) {
                    ii val = right.front();
                    right.pop();
                    val.second = tc + t;
                    v.push_back(val);
                    move = true;
                    count++;
                }
                if (move) {
                    tc += t;
                    site = 0;
                }
            }
            if (!move) {
                int t1 = -1, t2 = -1;
                if (!right.empty()) t1 = max(tc + (site == 1? 0: t), right.front().second + (site == 1? 0: t));
                if (!left.empty()) t2 = max(tc + (site == 0? 0: t), left.front().second + (site == 0? 0: t));
                if (t1 == -1) tc = t2, site = 0;
                else if (t2 == -1) tc = t1, site = 1;
                else {
                    if (right.front().second < left.front().second) tc = t1, site = 1;
                    else if (right.front().second > left.front().second) tc = t2, site = 0;
                    else tc = min(t1, t2);
                }
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            printf("%d\n", v[i].second);
        }
        if (T) printf("\n");
    }
    return 0;
}
