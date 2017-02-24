#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const unsigned NUM=100;
typedef long long int base_t;
const base_t BASE=1000000000;

struct bigint{
    bigint(long long int i=0) :used(0),sign((i>=0)?1:-1){
        memset(inner,0,NUM*sizeof(base_t));
        i*=sign;
        for(;i>=BASE;i=i/BASE) inner[used++]=i%BASE;
        inner[used++]=i;
    }
    bigint& operator+=(const bigint& b){
        used=min(max(b.used,used)+1, NUM); base_t carry=0;
        for(int i=0;i<used;i++) {
            carry=(inner[i]+=b.inner[i]+carry)/BASE;
            inner[i]%=BASE;
        }
        while(used!=0 && inner[used-1]==0) --used;
        return *this;
    }
    bigint operator+(bigint b) const { return b+=*this; }
    bigint& operator+=(base_t b) {
        int j=1; base_t carry=(inner[0]+=b)/BASE; inner[0]%=BASE;
        while(carry!=0){carry=(inner[j]+=carry)/BASE; inner[j++]%=BASE;}
        if(j>used && inner[j-1]!=0) used=j;
        return *this;
    }
    bigint operator+(base_t b) { bigint r(*this); return r+=b; }

    string str() const {
        stringstream ss;
        ss << sign*inner[used-1];
        for(int i=used-2;i>=0;i--)
            ss<<"00000000"+(int)(inner[i] ? floor(log10(inner[i])) : 0)
              << inner[i];
        return ss.str();
    }
    char sign;
    unsigned used;
    base_t inner[NUM];
};
bigint operator+(long long int i, const bigint& l) { return l+i; }

vector<bigint> dp;

void proc() {
    dp.push_back(bigint(1));
    dp.push_back(bigint(2));
    dp.push_back(bigint(5));
    for (int i = 3; i <= 1000; i++) {
        dp.push_back(dp[i - 1] + dp[i - 1] + dp[i - 2] + dp[i - 3]);
    }
}

/*vector<long long> dp2(1001, 0);

long long proc2(int n){
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp2[n] == 0) {
        dp2[n] = 2*proc2(n - 1) + proc2(n - 2) + proc2(n - 3);
    }
    return dp2[n];
}*/

int main() {
    proc();
    int n;
    while (cin >> n) {
        printf("%s\n", dp[n].str().c_str());
        //printf("%lld\n", proc2(n));
    }
    return 0;
}
