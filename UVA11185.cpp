#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    stack<char> s;
    while (cin >> n && n >= 0) {
        while (n >= 3) {
            s.push(n%3 + '0');
            n /= 3;
        }
        s.push(n + '0');
        while (!s.empty()) {
            printf("%c", s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}
