#include <iostream>
#include <utility>
using namespace std;

typedef pair<long long, long long> frac;

long long gcd(long long n, long long m) {
	long long auxi;
	if (m > n) {
		auxi = n;
		n = m, m = auxi;
	}
	while (m > 0) {
		auxi = n;
		n = m, m = auxi%m;
	}
	return n;
}

void add(frac & q, frac r) {
	q.first = q.first*r.second + r.first*q.second;
	q.second = q.second*r.second;
	long long d = gcd(q.first, q.second);
	q.first /= d, q.second /= d;
}

int main() {
	int T, N, list[10];
	cin >> T;
	for (int c = 1; c <= T; c++) {
		cin >> N;
		frac q(0, 1);
		for (int i = 0; i < N; i++) {
			cin >> list[i];
			frac r(1, list[i]);
			add(q, r);
		}
		q.second *= N;
		long long auxi = q.first;
		q.first = q.second, q.second = auxi;
		add(q, frac(0, 1));
		printf("Case %d: %lld/%lld\n", c, q.first, q.second);
	}
	return 0;
}