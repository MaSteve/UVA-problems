#include <iostream>
using namespace std;

long long toInt(long long b0, long long b1, long long b2, long long b3) {
    return (b0 << 24) | (b1 << 16) | (b2 << 8) | (b3);
}

long long MSOne(long long S) {
    int p = 0;
    while (S) {
        S >>= 1;
        p++;
    }
    return ((long long) 1) << p;
}

long long getMask(long long ip1, long long ip2) {
    long long x = ip1 ^ ip2;
    long long mask = ~(0);
    while (x) {
        x >>= 1;
        mask <<= 1;
    }
    return mask;
}

int main() {
    int m;
    while (cin >> m) {
        long long mask = ~(0), ip;
        long long b0, b1, b2, b3;
        char c;
        m--;
        cin >> b0 >> c >> b1 >> c >> b2 >> c >> b3;
        ip = toInt(b0, b1, b2, b3);
        while (m--) {
            cin >> b0 >> c >> b1 >> c >> b2 >> c >> b3;
            long long auxIp = toInt(b0, b1, b2, b3);
            if (ip == (auxIp & mask)) continue;
            mask = getMask(auxIp, ip);//&= ~(MSOne(ip ^ (auxIp & mask)) - 1);
            ip &= mask;
        }
        printf("%lld.%lld.%lld.%lld\n", (ip >> 24)&255, (ip >> 16)&255, (ip >> 8)&255, ip&255);
        printf("%lld.%lld.%lld.%lld\n", (mask >> 24)&255, (mask >> 16)&255, (mask >> 8)&255, mask&255);
    }
    return 0;
}
