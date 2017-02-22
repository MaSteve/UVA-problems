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

ld darea(point & a, point & b, point & c) {
    return imag(conj(a)*b+conj(b)*c+conj(c)*a);
}

point intersectSeg(point & p, point & q, point & a, point & b) {
    ld u = abs(imag(conj(a-b)*p-b*conj(a)));
    ld v = abs(imag(conj(a-b)*q-b*conj(a)));
    return (p*v + q*u) / (u+v);
}

polygon cutPolygon(point & a, point & b, polygon &p) {
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
    int N, W, H, x, y, c = 1;
    while (cin >> N >> W >> H >> x >> y) {
        polygon garden;
        point fountain(x, y);
        garden.push_back(point(0,0));
        garden.push_back(point(W,0));
        garden.push_back(point(W,H));
        garden.push_back(point(0,H));
        for (int i = 0; i < N; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            point a(x1, y1), b(x2, y2);
            if (darea(a, fountain, b) > 0) garden = cutPolygon(b, a, garden);
            else garden = cutPolygon(a, b, garden);
        }
        printf("Case #%d: %.3Lf\n", c++, area(garden));
    }
    return 0;
}
