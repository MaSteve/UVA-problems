#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    string s;
    unordered_map<string, string> m;
    while (getline(cin, s) && s != "") {
        istringstream iss(s);
        string sub1, sub2;
        iss >> sub1 >> sub2;
        m[sub2] = sub1;
    }
    while (getline(cin, s)) {
        if (m.count(s)) {
            printf("%s\n", m[s].c_str());
        }
        else printf("eh\n");
    }
    return 0;
}
