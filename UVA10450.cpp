#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> m;

long long proc(int val, int last) {
    if (!m.count(val*10 + last)) {
        m[val*10 + last] = proc(val-1, 0) + (last? 0: proc(val-1, 1));
    }
    return m[val*10 + last];
}

int main() {
    m[10] = 2;
    m[11] = 1;
    int n;
    cin >> n;
    for (int c = 1; c <= n; c++) {
        int val;
        cin >> val;
        printf("Scenario #%d:\n", c);
        printf("%lld\n", proc(val, 0));
        printf("\n");
    }
    return 0;
}
