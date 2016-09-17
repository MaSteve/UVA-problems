#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int n, k;
        queue<char> q;
        unordered_map<char, int> rec;
        cin >> n >> k;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (q.size() > k) {
                rec[q.front()]--;
                q.pop();
            }
            char p;
            cin >> p;
            if (rec[p]) count++;
            q.push(p);
            rec[p]++;
        }
        printf("Case %d: %d\n", c, count);
    }
    return 0;
}
