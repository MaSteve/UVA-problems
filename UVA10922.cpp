#include <iostream>
using namespace std;

int proc(int sum, bool & mul) {
    if (sum < 10) {
        mul = sum == 9;
        return 1;
    }
    int nsum = 0;
    while (sum != 0) {
        nsum += sum % 10;
        sum /= 10;
    }
    return proc(nsum, mul) + 1;
}

int main() {
    string s;
    while (cin >> s && s != "0") {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += s[i]-'0';
        }
        bool mul;
        int degree = proc(sum, mul);
        printf("%s ", s.c_str());
        if (mul) printf("is a multiple of 9 and has 9-degree %d.\n", degree);
        else printf("is not a multiple of 9.\n");
    }
    return 0;
}
