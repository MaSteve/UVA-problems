#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N <= 1) printf("%d\n", N);
        else {
            int div = 9;
            stack<int> s;
            while (div > 1 && N != 1) {
                if (N % div == 0) s.push(div), N /= div;
                else div --;
            }
            if (N == 1) {
                while (!s.empty()) printf("%d", s.top()), s.pop();
                printf("\n");
            } else printf("-1\n");
        }
    }
    return 0;
}
