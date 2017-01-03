#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll sieve_size;
bitset<10000010> bs;
vi primes;
vi codes;
unordered_map<int, int> m;

void sieve(ll upperbound = 10001) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.push_back((int)i);
        if (i > 1000 && i < 10000) m[i] = codes.size(), codes.push_back(i);
    }
}

#define N 1061
int AdjMat[N][N];

void floyd() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) {
                    AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                }
}

int main() {
    sieve();
    for (int i = 0; i < N; i++) {
        AdjMat[i][i] = 0;
        for (int j = i + 1; j < N; j++) {
            int c1 = codes[i], c2 = codes[j], match = 0;
            while (c1) {
                if (c1%10 == c2%10) match++;
                c1 /= 10, c2 /= 10;
            }
            if (match == 3) AdjMat[i][j] = AdjMat[j][i] = 1;
            else AdjMat[i][j] = AdjMat[j][i] = 2000;
        }
    }
    floyd();
    int T;
    scanf("%d", &T);
    while (T--) {
        int s, d;
        scanf("%d %d", &s, &d);
        s = m[s], d = m[d];
        if (AdjMat[s][d] >= 2000) printf("Impossible\n");
        else printf("%d\n", AdjMat[s][d]);
    }
    return 0;
}
