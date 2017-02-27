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

int main() {
    string fib[500];
    bigint f0(1), f1(2);
    fib[0] = string(129, '0') + f0.str(), fib[1] = string(129, '0') + f1.str();
    for (int i = 2; i < 500; i++) {
        bigint auxi = f0 + f1;
        f0 = f1;
        f1 = auxi;
        string s = f1.str();
        fib[i] = string(130-s.length(), '0') + s;
    }
    string a, b;
    while (cin >> a >> b && !(a == "0" && b == "0")) {
        a = string(130-a.length(), '0') + a;
        b = string(130-b.length(), '0') + b;
        printf("%d\n", upper_bound(fib, fib + 500, b) - lower_bound(fib, fib + 500, a));
    }
    return 0;
}
