#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string l;
    long long val, val2;
    while (cin >> val2) {
        getline(cin, l);
        getline(cin, l);
        stringstream ss(l);
        vector<long long> pol;
        while (ss >> val) pol.push_back(val);
        long long pot = 1, acum = 0;
        for (int i = pol.size() - 2, n = 1; i >= 0; i--, n++) {
            acum += pot*pol[i]*n;
            pot *= val2;
        }
        printf("%lld", acum);
        printf("\n");
    }
    return 0;
}
