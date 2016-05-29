#include <iostream>
using namespace std;

long long euclides(long long a, long long b, long long &x, long long &y){
    long long xx=y=0, yy=x=1;
    while(b) {
        long long q=a/b, t=b;
        b=a%b; a=t; t=xx; xx=x-q*xx;
        x=t; t=yy; yy=y-q*yy; y=t;
    }
    return a;
}

int main() {
    long long a, b, x, y, d;
    while (cin >> a >> b) {
        d = euclides(a, b, x, y);
        printf("%lld %lld %lld\n", x, y, d);
    }
    return 0;
}
