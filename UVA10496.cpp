#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;

int X, Y, sx, sy, beepers;
ii pos[12];
unordered_map <int, unordered_map <int, int> > dp;

int func(int x, int y, int visited) {
    if (!dp.count(100*x + y) || !dp[100*x + y].count(visited)) {
        int ret = 400000;
        bool last = true;
        for (int i = 0; i < beepers; i++) {
            if ((visited >> i) % 2 == 0) {
                last = false;
                int val = func(pos[i].first, pos[i].second, (visited | (1<<i))) + fabs(pos[i].first - x) + fabs(pos[i].second - y);
                ret = min(ret, val);
            }
        }
        if (last) ret = fabs(sx - x) + fabs(sy - y);
        dp[100*x+y][visited] = ret;
    }
    return dp[100*x+y][visited];
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        dp.clear();
        cin >> X >> Y >> sx >> sy >> beepers;
        for (int i = 0; i < beepers; i++) {
            cin >> pos[i].first >> pos[i].second;
        }
        printf("The shortest path has length %d\n", func(sx, sy, 0));
    }
    return 0;
}
