#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    int n, n1, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        int c = 1;
        n1 = n;
        int prev = n/m;
        n %= m;
        unordered_map<int, int> mv;
        queue<int> rq;
        while (!(n == 0 || mv.count(n))) {
            mv[n] = c;
            c++;
            n *= 10;
            rq.push(n/m);
            n %= m;
        }
        if (n == 0) {
            rq.push(0);
            mv[n] = c;
            c++;
        }
        printf("%d/%d = %d.", n1, m, prev);
        for (int i = 0; i < 50 && !rq.empty(); i++) {
            if (i == mv[n] - 1) printf("(");
            printf("%d", rq.front());
            rq.pop();
        }
        if (!rq.empty()) printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", c - mv[n]);
    }
    return 0;
}
