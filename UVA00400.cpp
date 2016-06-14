#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> v;
    int n;
    while (cin >> n) {
        v.clear();
        int m = 0;
        while (n--) {
            string in;
            cin >> in;
            v.push_back(in);
            m = max(m, (int)in.length());
        }
        sort(v.begin(), v.end());
        int col = (60-m)/(m+2) + 1;
        cout << "------------------------------------------------------------\n";
        int div = v.size()/col + (v.size()%col? 1: 0);
        for (int i = 0; i < div; i++) {
            for (int j = 0; j < col; j++) {
                if (j == col - 1) cout.width(m);
                else cout.width(m+2);
                if (i+j*(div) < v.size()) cout << left << v[i+j*(div)];
            }
            cout << endl;
        }
    }
    return 0;
}
