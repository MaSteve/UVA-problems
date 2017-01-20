#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef complex<ld> point, vect;
typedef vector<point> polygon;
typedef polygon::iterator polIter;
const ld inf = 1e9; const ld eps = 1e-9; const ld pi = acos(-1.0);

ld area(polygon &p) {
	ld result = 0.0;
	for (int i = 0; i < p.size(); i++)
		result += imag(conj(p[i])*p[(i+1)%p.size()]);
	return abs(result) / 2.0;
}

double dist(point p1, point p2) {
    return hypot(p1.real() - p2.real(), p1.imag() - p2.imag());
}

double cross(vect a, vect b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

vect toVec(point a, point b) {
    return vect(b.real() - a.real(), b.imag() - a.imag());
}

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < eps;
}

point pivot(0, 0);
bool angleCmp(point a, point b) {
    if (collinear(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
    double d1x = a.real() - pivot.real(), d1y = a.imag() - pivot.imag();
    double d2x = b.real() - pivot.real(), d2y = b.imag() - pivot.imag();
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

polygon CH(polygon P) {
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]);
            return P;
    }
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].imag() < P[P0].imag() || (P[i].imag() == P[P0].imag() && P[i].real() > P[P0].real()))
            P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    polygon S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while (i < n) {
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    return S;
}

int main() {
    int N, c = 1;
    while (cin >> N && N != 0) {
        polygon pol;
        for (int i = 0; i < N; i++) {
            double x, y;
            cin >> x >> y;
            pol.push_back(point(x, y));
        }
        ld tArea = abs(area(pol));
        polygon chull = CH(pol);
        ld hArea = abs(area(chull));
        printf("Tile #%d\n", c);
        printf("Wasted Space = %.2Lf %%\n\n", ((hArea-tArea)*100)/hArea);
        c++;
    }
    return 0;
}
