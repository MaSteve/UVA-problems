#include <iostream>
#include <vector>
#include <string>
using namespace std;

char str[12];
vector<string> sol;
int N, K;
string s;

void proc(int pos, int K) {
    if (pos == N) {
        str[pos] = 0;
        sol.push_back(string(str));
        return;
    }
    if (K == 0) {
        str[pos] = s[pos];
        proc(pos+1, K);
        return;
    }
    str[pos] = 'A';
    proc(pos+1, str[pos] == s[pos]? K: K-1);
    str[pos] = 'C';
    proc(pos+1, str[pos] == s[pos]? K: K-1);
    str[pos] = 'G';
    proc(pos+1, str[pos] == s[pos]? K: K-1);
    str[pos] = 'T';
    proc(pos+1, str[pos] == s[pos]? K: K-1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K >> s;
        sol.clear();
        proc(0, K);
        printf("%ld\n", sol.size());
        for (int i = 0; i < sol.size(); i++) {
            printf("%s\n", sol[i].c_str());
        }
    }
    return 0;
}
