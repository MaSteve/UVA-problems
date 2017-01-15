#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    set<long long> s;
    unordered_map<long long, int> m;
    for (long long i = 1; i <= 1001; i++) {
        for (long long j = i; j <= 1001; j++) {
            long long val = (i*i*i + j*j*j);
            m[val]++;
            if (m[val] > 1) s.insert(val);
        }
    }
    long long n1, rg;
    while (cin >> n1 >> rg) {
        auto it = s.lower_bound(n1);
        bool ok = false;
        while (it != s.end()) {
            if (*it > n1 + rg) break;
            ok = true;
            printf("%lld\n", *it);
            ++it;
        }
        if (!ok) printf("None\n");
    }
    return 0;
}
