#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

int mod = 1000000009;

struct lll {
    long long first;
    long long second;
    long long third;
    lll (long long f, long long s, long long t) {
        first = f;
        second = s;
        third = t;
    }
    lll () {}
};
struct mat {
    lll first;
    lll second;
    lll third;
    mat () {}
    mat (lll f, lll s, lll t) {
        first = f;
        second = s;
        third = t;
    }
};

mat prod(const mat & mn0, const mat & mn1) {
    mat mn2(lll(
    (mn0.first.first*mn1.first.first + mn0.first.second*mn1.second.first + mn0.first.third*mn1.third.first)%mod,
    (mn0.first.first*mn1.first.second + mn0.first.second*mn1.second.second + mn0.first.third*mn1.third.second)%mod,
    (mn0.first.first*mn1.first.third + mn0.first.second*mn1.second.third + mn0.first.third*mn1.third.third)%mod),
    lll(
    (mn0.second.first*mn1.first.first + mn0.second.second*mn1.second.first + mn0.second.third*mn1.third.first)%mod,
    (mn0.second.first*mn1.first.second + mn0.second.second*mn1.second.second+mn0.second.third*mn1.third.second)%mod,
    (mn0.second.first*mn1.first.third + mn0.second.second*mn1.second.third + mn0.second.third*mn1.third.third)%mod),
    lll(
    (mn0.third.first*mn1.first.first + mn0.third.second*mn1.second.first + mn0.third.third*mn1.third.first)%mod,
    (mn0.third.first*mn1.first.second + mn0.third.second*mn1.second.second + mn0.third.third*mn1.third.second)%mod,
    (mn0.third.first*mn1.first.third + mn0.third.second*mn1.second.third + mn0.third.third*mn1.third.third)%mod)
    );
    return mn2;
}

unordered_map<long long, mat> dp;
mat mat1 = mat(lll(1, 1, 0), lll(1, 0, 1), lll(1, 0, 0));

mat pow(long long n) {
    if (n == 0) return mat(lll(1, 0, 0), lll(0, 1, 0), lll(0, 0, 1));
    if (n == 1) return mat1;
    if (!dp.count(n)) {
        mat mn1 = pow(n/2);
        mat mn2 = prod(mn1, mn1);
        if (n%2) {
            mn2 = prod(mn2, mat1);
        }
        dp[n] = mn2;
    }
    return dp[n];
}

int main() {
    long long n;
    while (cin >> n && n) {
        long long val =  pow(n).second.second%mod;
        printf("%lld\n", val);
    }
    return 0;
}
