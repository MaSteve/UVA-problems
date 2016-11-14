#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

typedef pair<long long, long long> ll;
typedef pair<ll, ll> mat;

unordered_map<int, mat> dp;

int mod = 0x00FFFFFF;

mat pow(int n) {
    if (n == 0) return mat(ll(1, 0), ll(0, 1));
    if (n == 1) return mat(ll(1, 1), ll(1, 0));
    if (!dp.count(n)) {
        mat mn1 = pow(n/2);
        mat mn2(ll((mn1.first.first*mn1.first.first + mn1.first.second*mn1.second.first)&mod, (mn1.first.first*mn1.first.second + mn1.first.second*mn1.second.second)&mod), ll((mn1.second.first*mn1.first.first + mn1.second.second*mn1.second.first)&mod, (mn1.second.first*mn1.first.second + mn1.second.second*mn1.second.second)&mod));
        if (n%2) {
            mn1 = mn2;
            mn2 = mat(ll(mn1.first.first+mn1.second.first, mn1.first.second+mn1.second.second), ll(mn1.first.first, mn1.first.second));
        }
        dp[n] = mn2;
    }
    return dp[n];
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        long long val =  pow(n).first.second & ((1<<m)-1);
        printf("%lld\n", val);
    }
    return 0;
}
