#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, unsigned long long> map;

unsigned long long proc(int n, int s, bool lock) {
    if (s > n || s <= -1 || (s == n && !lock)) return 0;
    if (n == 1) return s == 1? (lock? 1: 0): (lock? 1: 2);
    if (s == n) return 1;
    if (!map.count(n*1000 + s*10 + (lock? 1: 0))) {
        unsigned long long val = 0;
        /*if (s == 0) {
            if (lock) val += proc(n-1, s, false);
            else {
                val += proc(n-1, s, false);
                val += proc(n-1, s, true);
            }
        } else {*/
            val += proc(n-1, s, false);
            if (lock) val += proc(n-1, s-1, true);
            else val += proc(n-1, s, true);
        //}
        map[n*1000 + s*10 + (lock? 1: 0)] = val;
    }
    return map[n*1000 + s*10 + (lock? 1: 0)];
}

int main() {
    int n, s;
    while (cin >> n >> s && !(n < 0 && s < 0)) {
        printf("%llu\n", proc(n, s, true));
    }
    return 0;
}
