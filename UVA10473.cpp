#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    string s;
    char buffer[20];
    while (getline(cin, s) && s[0] != '-') {
        if (s[0] == '0' && s[1] == 'x') {
            int val = stoi (s,nullptr,16);
            printf("%d\n", val);
        } else {
            int dec = stoi (s,nullptr,10);
            sprintf(buffer, "0x%X", dec);
            printf("%s\n", buffer);
        }
    }
    return 0;
}
