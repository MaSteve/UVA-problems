#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "1" || s == "4" || s == "78") printf("+\n");
        else if (s[s.length()-2] == '3' && s[s.length()-1] == '5') printf("-\n");
        else if (s[0] == '9' && s[s.length()-1] == '4') printf("*\n");
        else /*if (s[0] == '1' && s[1] == '9' && s[2] == '0')*/ printf("?\n");
    }
    return 0;
}
