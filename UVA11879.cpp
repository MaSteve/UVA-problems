#include <iostream>
using namespace std;

int main() {
    string n;
    while (cin >> n && n != "0") {
        int l = n.length(), i = 0;
        while (i < l - 1 && n[i] == '0') i++;
        while (l - i > 6) {
            int val = (n[l-1]-'0')*5;
            if (n[l-2]-'0' < val%10) val += 10;
            n[l-2] = (n[l-2]-'0'+10-val%10)%10 + '0';
            val /= 10;
            bool carry = n[l-3]-'0' < val%10;
            n[l-3] = (n[l-3]-'0'+10-val%10)%10 + '0';
            int pos = l - 4;
            while (carry) {
                carry = n[pos] == '0';
                n[pos] = (n[pos]-'0'+9)%10 + '0';
                pos--;
            }
            l--;
        }
        int check = atoi(n.substr(i, l - i).c_str());
        if (check % 17 == 0) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
