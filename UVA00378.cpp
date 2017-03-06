#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

typedef long double ld;
typedef vector<int> vi;

const ld inf=1e9;
const ld eps=1e-9;
const ld pi=acos(-1.0);

typedef complex<ld> point, vect;
struct line {
    ld a; ld b;
    ld c;
};

line pointsToLine(point a, point b) {
    line result;
    result.a=b.imag()-a.imag();
    result.b=a.real()-b.real();
    result.c=a.imag()*b.real()-a.real()*b.imag();
    return result;
}

point intersection(line r, line s) {
    ld den=r.b*s.a-r.a*s.b;
    point result( (r.c*s.b-r.b*s.c)/den , (r.a*s.c-r.c*s.a)/den );
    return result;
}

double cross(vect a, vect b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

vect toVec(point a, point b) {
    return vect(b.real() - a.real(), b.imag() - a.imag());
}

int main() {
    printf("INTERSECTING LINES OUTPUT\n");
    int N;
    cin >> N;
    line lx = pointsToLine(point(0, 0), point(0, 1));
    while (N--) {
        ld x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
        line l1 = pointsToLine(p1, p2);
        line l2 = pointsToLine(p3, p4);
        if (abs(l1.a*l2.b - l1.b*l2.a) < eps) {
            if (abs(cross(toVec(p1, p2), toVec(p1, p3))) < eps) printf("LINE\n");
            else printf("NONE\n");
        } else {
            point p = intersection(l1, l2);
            ld x = p.real();
            ld y = p.imag();
            if (abs(x) < eps) x = 0;
            if (abs(y) < eps) y = 0;
            printf("POINT %.2Lf %.2Lf\n", x, y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
