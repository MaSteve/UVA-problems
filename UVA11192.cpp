#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    while (cin >> n && n != 0) {
        cin >> s;
        n = s.length()/n;
        for (int i = 0; i < s.length(); i += n) {
            for (int j = 0; j < n/2; j++) {
                char aux = s[j+i];
                s[j+i] = s[i+n-1-j];
                s[i+n-1-j] = aux;
            }
        }
        cout << s << endl;
    }
    return 0;
}
