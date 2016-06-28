#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    int cases = 1;
    bool ok = true;
    unordered_map<string, int> m;
    while (cin >> s) {
        if (s == "9") {
            if (ok) printf("Set %d is immediately decodable\n", cases++);
            else printf("Set %d is not immediately decodable\n", cases++);
            m.clear();
            ok = true;
        } else if (ok) {
            for (int i = 1; i < s.length(); i++) {
                if (m[s.substr(0,i)] == 1) ok = false;
            }
            if (m.count(s)) ok = false;
            m[s] = 1;
        }
    }
    return 0;
}
