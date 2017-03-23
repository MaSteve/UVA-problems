#include <iostream>
#include <stack>
using namespace std;

int ctoi(char c) {
    if (c - 'A' >= 0) return c - 'A' + 10;
    else return c - '0';
}

char itoc(int i) {
    if (i < 10) return i + '0';
    else return i + 'A' - 10;
}

int main() {
    string n;
    int b1, b2;
    while (cin >> n >> b1 >> b2) {
        int val = 0;
        for (int i = 0; i < n.length(); i++) {
            val *= b1;
            val += ctoi(n[i]);
        }
        stack<char> s;
        while (val) {
            s.push(itoc(val%b2));
            val /= b2;
        }
        if (s.size() > 7) printf("  ERROR\n");
        else {
            for (int i = 6; i >= s.size(); i--) {
                printf(" ");
                if (i == 1 && s.size() == 0) {
                    printf("0");
                    break;
                }
            }
            while (!s.empty()) {
                printf("%c", s.top());
                s.pop();
            }
            printf("\n");
        }
    }
    return 0;
}
