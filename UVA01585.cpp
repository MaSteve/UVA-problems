#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        int sum = 0, acum = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'O') sum += (acum++);
            else acum = 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}
