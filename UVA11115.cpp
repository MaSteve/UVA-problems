#include <iostream>
#include <cmath>
#include <stack>
using namespace std;



int main() {
    int N, D;
    while (cin >> N >> D && !(N == 0 && D == 0)) {
        __int128_t p = 1;
        for (int i = 0; i < D; i++) p *= N;
        stack<int> s;
        while (p) {
            s.push(p%10);
            p /= 10;
        }
        while (!s.empty()) {
            printf("%d", s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}
