#include <iostream>
#include <queue>
#include <utility>
#include <unordered_set>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

int a, b, c, d;

void proc(int & i1, int & i2, int l1, int l2, int & move) {
    int auxi = l2 - i2;
    if (i1 > auxi) i1 -= auxi, i2 = l2, move -= auxi;
    else i2 += i1, move -= i1, i1 = 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        priority_queue<iiii> q;
        unordered_set<int> s;
        q.push(iiii(ii(0, 0), ii(0, c)));
        int dt = c <= d? c: 0, steps = 0;
        while (!q.empty() && dt < d) {
            iiii state = q.top(); q.pop();
            if (state.first.second <= d && state.first.second > dt) dt = state.first.second, steps = -state.first.first;
            if (state.second.first <= d && state.second.first > dt) dt = state.second.first, steps = -state.first.first;
            if (state.second.second <= d && state.second.second > dt) dt = state.second.second, steps = -state.first.first;
            if (dt == d) break;
            if (!s.count(state.first.second*1000000 + state.second.first*1000 + state.second.second)) {
                s.insert(state.first.second*1000000 + state.second.first*1000 + state.second.second);
                iiii co = iiii(state);
                proc(co.first.second, co.second.first, a, b, co.first.first);
                q.push(co);
                co = iiii(state);
                proc(co.second.first, co.first.second, b, a, co.first.first);
                q.push(co);
                co = iiii(state);
                proc(co.first.second, co.second.second, a, c, co.first.first);
                q.push(co);
                co = iiii(state);
                proc(co.second.second, co.first.second, c, a, co.first.first);
                q.push(co);
                co = iiii(state);
                proc(co.second.first, co.second.second, b, c, co.first.first);
                q.push(co);
                co = iiii(state);
                proc(co.second.second, co.second.first, c, b, co.first.first);
                q.push(co);
            }
        }
        printf("%d %d\n", steps, dt);
    }
    return 0;
}
