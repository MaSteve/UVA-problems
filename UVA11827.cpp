#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

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

int main() {
    int N, val[101];
    cin >> N;
    string s;
    getline(cin, s);
    while (N--) {
        getline(cin, s);
        stringstream ss(s);
        int n = 0, maxi = 1;
        while (ss >> val[n]) n++;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxi = max(ll(maxi), gcd(val[i], val[j]));
            }
        }
        printf("%d\n", maxi);
    }
    return 0;
}
