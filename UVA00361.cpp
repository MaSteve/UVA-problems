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

ld angle(vect v, vect u) {
    return arg(v/u);
}

int inPolygon(point q, polygon &p) {
    int n=p.size(); if(n==0) return -1;
    ld sum=0.0, alpha;
    for (int i=0; i<n-1; i++) {
        if(dist(p[i],q)<eps||dist(p[(i+1)%n],q)<eps) return 0;
        alpha=angle(p[(i+1)%n]-q,p[i]-q);
        if(fabs(alpha-pi)<eps) return 0;
        sum+=alpha;
    }
    return (abs(sum)<eps)?-1:1;
}

polygon empty;

int main() {
    int c, r, o, t = 1;
    while (cin >> c >> r >> o && !(c == 0 && r == 0 && o == 0)) {
        int x, y;
        polygon cops, robbers;
        for (int i = 0; i < c; i++) {
            cin >> x >> y;
            cops.push_back(point(x, y));
        }
        for (int i = 0; i < r; i++) {
            cin >> x >> y;
            robbers.push_back(point(x, y));
        }
        polygon chcops = c > 2? CH(cops): empty;
        polygon chrobbers = r > 2? CH(robbers): empty;
        printf("Data set %d:\n", t++);
        for (int i = 0; i < o; i++) {
            cin >> x >> y;
            point p(x, y);
            if (inPolygon(p, chcops) != -1) {
                printf("     Citizen at (%d,%d) is safe.\n", x, y);
            } else if (inPolygon(p, chrobbers) != -1) {
                printf("     Citizen at (%d,%d) is robbed.\n", x, y);
            } else printf("     Citizen at (%d,%d) is neither.\n", x, y);
        }
        printf("\n");
    }
    return 0;
}
