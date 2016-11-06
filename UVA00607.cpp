#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int L, C, n, counter;

inline int proc(int t) {
    if (t == 0) return t;
    if (t <= 10) return -C;
    return (t-10)*(t-10);
}

int v[1002];
unordered_map<int, int> m;

int func(int tid, int day) {
    if (day > counter) return 1000000000;
    if (tid >= n) return 0;
    if (!m.count(tid*10000+day)) {
        int acum = 0, mini = 1000000000;
        for (int i = tid; i < n; i++) {
            acum += v[i];
            if (acum > L) break;
            mini = min(mini, proc(L-acum) + func(i+1, day+1));
        }
        m[tid*10000+day] = mini;
    }
    return m[tid*10000+day];
}

int main() {
    int c = 1;
    while (cin >> n && n != 0) {
        if (c > 1) printf("\n");
        int acum = 0;
        counter = 1;
        cin >> L >> C;
        m.clear();
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            v[i] = t;
            acum += t;
            if (acum > L) counter++, acum = t;
        }
        int minDI = func(0, 0);
        printf("Case %d:\n", c);
        printf("Minimum number of lectures: %d\n", counter);
        printf("Total dissatisfaction index: %d\n", minDI);
        c++;
    }
    return 0;
}
