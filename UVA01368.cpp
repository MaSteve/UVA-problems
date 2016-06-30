#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int cases;
    vector<string> v;
    cin >> cases;
    while (cases--) {
        v.clear();
        int n, m;
        cin >> m >> n;
        string s;
        for (int i = 0; i < m; i++) {
            cin >> s;
            v.push_back(s);
        }
        s = string(n, ' ');
        int d = 0;
        for (int i = 0; i < n; i++) {
            int A = 0, C = 0, G = 0, T = 0;
            for (int j = 0; j < m; j++) {
                if (v[j][i] == 'A') A++;
                if (v[j][i] == 'C') C++;
                if (v[j][i] == 'G') G++;
                if (v[j][i] == 'T') T++;
            }
            int maxi = max(max(A, C), max(G, T));
            if (A == maxi) s[i] = 'A';
            else if (C == maxi) s[i] = 'C';
            else if (G == maxi) s[i] = 'G';
            else if (T == maxi) s[i] = 'T';
            d += A + C + G + T - maxi;
        }
        cout << s << endl << d << endl;
    }
    return 0;
}
