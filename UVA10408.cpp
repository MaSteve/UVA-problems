#include <iostream>
#include <set>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll gcd(ll n, ll m) {
    ll auxi;
    if (m > n) {
        auxi = n;
        n = m, m = auxi;
    }
    while (m != 0) {
        auxi = n;
        n = m, m = auxi%m;
    }
    return n;
}

struct comp {
    bool operator() (const ii& lhs, const ii& rhs) const {
        return lhs.first * rhs.second < rhs.first * lhs.second;
    }
};

int main() {
    set<ii, comp> Farey;
    Farey.insert(ii(1,1));
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            if (gcd(j, i) == 1) {
                Farey.insert(ii(j, i));
            }
        }
    }
    int n, k;
    while (cin >> n >> k) {
        auto it = Farey.begin();
        while (true) {
            if (it->second <= n) {
                k--;
                if (k == 0) break;
            }
            ++it;
        }
        printf("%d/%d\n", it->first, it->second);
    }
    return 0;
}
