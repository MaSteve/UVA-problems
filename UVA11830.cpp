#include <iostream>
#include <queue>
using namespace std;

int main() {
    char D;
    string N;
    queue<char> q;
    while (cin >> D >> N && !(D == '0' && N == "0")) {
        bool leading = true;
        for (int i = 0; i < N.length(); i++) {
            if (N[i] != D) {
                if (!(leading && N[i] == '0')) {
                    leading = false;
                    q.push(N[i]);
                }
            }
        }
        if (q.empty()) printf("0");
        while (!q.empty()) {
            printf("%c", q.front());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}
