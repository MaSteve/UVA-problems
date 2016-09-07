#include <iostream>
#include <set>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

vector<set<ii> > sol;
bool used[10];
int num = 0, den = 0;

void proc(int p) {
    if (p == 10) {
        if (num%den == 0) {
            sol[num/den].insert(make_pair(num, den));
        }
    } else {
        for (int i = 9; i >= 0; i--) {
            if (!used[i]) {
                used[i] = true;
                if (p < 5) num = num*10 + i;
                else den = den*10 + i;
                proc(p+1);
                used[i] = false;
                if (p < 5) num /= 10;
                else den /= 10;
            }
        }
    }
}

int main() {
    sol.assign(81, set<ii>());
    for (int i = 0; i < 10; i++)  used[i] = false;
    proc(0);
    int N;
    bool first = false;
    while (cin >> N && N != 0) {
        if (first) printf("\n");
        else first = true;
        if (sol[N].size() == 0) printf("There are no solutions for %d.\n", N);
        else {
            for (auto it = sol[N].begin(); it != sol[N].end(); ++it) {
                ii f = *it;
                printf("%.5d / %.5d = %d\n", f.first, f.second, N);
            }
        }
    }
    return 0;
}
