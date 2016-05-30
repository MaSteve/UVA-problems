#include <iostream>
#include <set>
using namespace std;

void proc(long long n, long long & can, long long pot, int carry) {
    if (n / (pot) == 0) return;
    can += (((can/pot)%10 - carry - (n/pot)%10 + 20) % 10)*10*pot;
    proc(n, can, 10*pot, ((can/pot)%10) - carry < (can/(10*pot))%10? 1: 0);
}

int main() {
    long long n;
    while (cin >> n && n != 0) {
        bool first = false;
        set<long long> ret;
        for (int i = 0; i < 10; i++) {
            long long can = (i)*10 + (n%10 + i)%10;
            proc(n, can, 10, (n%10 + i)%10 < i? 1: 0);
            if (can - can/10 == n) ret.insert(can);
        }
        for (auto it = ret.begin(); it != ret.end(); ++it) {
            if (first) printf(" ");
            else first = true;
            printf("%lld", *it);
        }
        printf("\n");
    }
    return 0;
}
