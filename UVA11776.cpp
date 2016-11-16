#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int N, c = 1;
    while (cin >> N && N != -1) {
        priority_queue<ii> open, close;
        for (int i = 0; i < N; i++) {
            int S, E;
            cin >> S >> E;
            open.push(make_pair(-S, -E));
        }
        int o = 0, max = 0;
        close.push(make_pair(-10000000000, -10000000000));
        while (!open.empty()) {
            if (open.top().first < close.top().first) {
                close.pop();
                o--;
            } else {
                ii u = open.top();
                open.pop();
                o++;
                if (o > max) max = o;
                close.push(make_pair(u.second, u.first));
            }
        }
        printf("Case %d: %d\n", c, max);
        c++;
    }
    return 0;
}
