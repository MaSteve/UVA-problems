#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string l;
    while (getline(cin, l)) {
        stringstream ss(l);
        long long val;
        vector<long long> pol;
        while (ss >> val) pol.push_back(val);
        getline(cin, l);
        stringstream ss2(l);
        bool first = false;
        while (ss2 >> val) {
            long long pot = 1, acum = 0;
            for (int i = pol.size() - 1; i >= 0; i--) {
                acum += pot*pol[i];
                pot *= val;
            }
            if (first) printf(" ");
            else first = true;
            printf("%lld", acum);
        }
        printf("\n");
    }
    return 0;
}
