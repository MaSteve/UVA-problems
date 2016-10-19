#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<int, unordered_map<int, long long> > comb;
long long proc(int n, int m) {
    if (m == 0 || m == n) return 1;
    if (m < 0 || m > n) return 0;
    if (comb[n][m] == 0) comb[n][m] = proc(n-1, m-1) + proc(n-1, m);
    return comb[n][m];
}

int bucket[26];

long long proc(string & s, int p) {
    if (p == s.length() - 1) return 1;
    long long val = 0;
    for (int i = 0; i < s[p] - 'a'; i++) {
        if (bucket[i] > 0) {
            bucket[i]--;
            long long coef = 1, N = s.length() - 1 - p;
            for (int j = 0; j < 26; j++) {
                coef *= proc(N, bucket[j]);
                N -= bucket[j];
            }
            val += coef;
            bucket[i]++;
        }
    }
    bucket[s[p] - 'a']--;
    val += proc(s, p+1);
    bucket[s[p] - 'a']++;
    return val;
}

int main() {
    string s;
    while (cin >> s && s != "#") {
        for (int i = 0; i < 26; i++) bucket[i] = 0;
        for (int i = 0; i < s.length(); i++) bucket[s[i]-'a']++;
        printf("%10lld\n", proc(s, 0));
    }
    return 0;
}
