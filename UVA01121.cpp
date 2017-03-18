#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, S;
    while (cin >> N >> S) {
        queue<int> q;
        int sum = 0, len = N + 2;
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            sum += val;
            q.push(val);
            while (sum >= S) {
                len = min(len, (int) q.size());
                if (q.empty()) break;
                sum -= q.front();
                q.pop();
            }
        }
        if (len == N + 2) len = 0;
        printf("%d\n", len);
    }
    return 0;
}
