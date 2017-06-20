#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> candidates;
    unordered_map<string, int> votes;
    int T;
    cin >> T;
    while (T--) {
        candidates.clear();
        votes.clear();
        int n;
        cin >> n;
        string s;
        getline(cin, s);
        for (int i = 0; i < n; i++) {
            string party;
            getline(cin, s);
            getline(cin, party);
            candidates[s] = party;
        }
        int m;
        cin >> m;
        getline(cin, s);
        int maxi = -1;
        string winner;
        for (int i = 0; i < m; i++) {
            getline(cin, s);
            votes[s]++;
            if (votes[s] > maxi) maxi = votes[s], winner = candidates[s];
            else if (votes[s] == maxi) winner = "tie";
        }
        printf("%s\n", winner.c_str());
        if (T) printf("\n");
    }
    return 0;
}
