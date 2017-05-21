#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef __int128 ll;

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

string tostr(ll n) {
    char str[40];
    int i = 0;
    while (n) {
        str[i] = n%10 + '0';
        n /= 10;
        i++;
    }
    str[i] = 0;
    reverse(str, str + i);
    string s(str);
    return s;
}

ll toll(string s) {
    ll ret = 0;
    for (int i = 0; i < s.length(); i++) {
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

int main() {
    string ps, qs;
    ll p, q;
    char c;
    int T;
    cin >> T;
    while (T--) {
        cin >> ps >> c >> qs;
        p = toll(ps), q = toll(qs);
        ll g = gcd(p, q);
        p /= g, q /= g;
        cout << tostr(p) << " / " << tostr(q) << endl;
    }
    return 0;
}
