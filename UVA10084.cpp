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

ld darea(point a, point b, point c) {
    return imag(conj(a)*b+conj(b)*c+conj(c)*a);
}

ld area(polygon &p) {
    ld result = 0.0;
    for (int i = 0; i < p.size(); i++)
        result += imag(conj(p[i])*p[(i+1)%p.size()]);
    return abs(result) / 2.0;
}

point intersectSeg(point p, point q, point a, point b) {
    ld u = abs(imag(conj(a-b)*p-b*conj(a)));
    ld v = abs(imag(conj(a-b)*q-b*conj(a)));
    return (p*v + q*u) / (u+v);
}

polygon cutPolygon(point a, point b, polygon &p) {
    polygon q;
    for (int i = 0; i < p.size(); i++) {
        ld left1 = darea(a, b, p[i]);
        ld left2 = darea(a, b, p[(i + 1)%p.size()]);
        if (left1 > -eps) q.push_back(p[i]);
        if (left1*left2 < -eps)
            q.push_back(intersectSeg(p[i],p[(i+1)%p.size()],a,b));
    }
    return q;
}

int main() {
    point a(0, 0), b;
    polygon pol;
    bool empty = false;
    pol.push_back(point(0, 0));
    pol.push_back(point(10, 0));
    pol.push_back(point(10, 10));
    pol.push_back(point(0, 10));
    ld val = area(pol);
    ld x, y;
    string s;
    while (cin >> x >> y >> s) {
        if (!empty) {
            b = point(x, y);
            if (a == b) {
                if (s == "Same") printf("%.2Lf\n", val);
                else {
                    empty = true;
                    printf("0.00\n");
                }
            }
            else {
                point c = (a + b) * point(0.5, 0);
                point d(c.imag() - b.imag(), b.real() - c.real());
                d += c;
                if (s == "Colder") pol = cutPolygon(c, d, pol);
                else if (s == "Hotter") pol = cutPolygon(d, c, pol);
                else empty = true;
                val = area(pol);
                if (val < 0.0001) empty = true;
                if (empty) printf("0.00\n");
                else printf("%.2Lf\n", val);
                a = b;
            }
        } else printf("0.00\n");
    }
    return 0;
}
