#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


const unsigned NUM=100; //number of elementes in array

typedef long long int base_t; //base type used
const base_t BASE=1000000000; //base for numbers, 10^9

struct bigint{
    bigint(long long int i=0) :used(0),sign((i>=0)?1:-1){
	memset(inner,0,NUM*sizeof(base_t)); // Change this for speed
	i*=sign;
	for(;i>=BASE;i=i/BASE)
	    inner[used++]=i%BASE;
	inner[used++]=i;
    }
    
    bigint& operator<<=(unsigned i){ //shift by base
	memmove(inner+i,inner,min(used,NUM-i)*sizeof(base_t)); used+=i;
	memset(inner,0,i*sizeof(base_t));
	return *this;
    }
    bigint operator<<(unsigned i) { bigint r(*this); return r<<=i; }


    bigint& operator+=(const bigint& b){
	if(sign!=b.sign){ sign*=-1; *this-=b; sign*=-1; return *this; }
	used=min(max(b.used,used)+1 , NUM); base_t carry=0;
	for(int i=0;i<used;i++){
	    carry=(inner[i]+=b.inner[i]+carry)/BASE; inner[i]%=BASE; }
	while(used!=0 && inner[used-1]==0) --used;
	return *this;
    }
    bigint operator+(bigint b) const{ return b+=*this; }

    bigint& operator+=(base_t b){
	int j=1; base_t carry=(inner[0]+=b)/BASE; inner[0]%=BASE; 
	while(carry!=0){carry=(inner[j]+=carry)/BASE; inner[j++]%=BASE;}
	if(j>used && inner[j-1]!=0) used=j;
	return *this;
    }
    bigint operator+(base_t b){ bigint r(*this); return r+=b; }

    bigint& operator-=(const bigint& b){
	if(b.sign!=sign){ sign*=-1; *this+=b; sign*=-1; return *this; }	
	base_t carry=0, buf[NUM], *M=inner; base_t const *m=b.inner;
	if(used<b.used || used==b.used&&inner[used-1]<b.inner[used-1]){
	    memcpy(buf,b.inner,b.used*sizeof(base_t));
	    sign*=-1; used=b.used; m=inner; M=buf;
	}

	for(int i=0;i<min(used,NUM);i++)
	    carry=(inner[i]=M[i]-(m[i]+carry))<0 ? (inner[i]+=BASE,1):0;
	while(used!=0 && inner[used-1]==0) --used;
	return *this;
    }
    bigint operator-(bigint b) const{ b-=*this; b.sign*=-1;return b;}


    bigint& operator*=(const bigint& b){
	base_t buf[NUM],j=0,carry=0;
	bigint const *m, *M= (used>b.used)? (m=&b,this) : (m=this,&b);
	for(unsigned i=0;i<m->used; i++)
	    for((j=0),carry=0; j<=(min(M->used,max(0U,NUM-i-1))) ; j++){
		carry=(buf[j+i]=(M->inner[j]*(m->inner[i]))+carry)/BASE;
		buf[j+i]%=BASE;
	    }
	used=min(used+b.used,NUM); sign*=b.sign;
	memcpy(inner,buf,used*sizeof(base_t));
	while(used && !inner[used-1]) --used;
	return *this;
    }
    bigint operator*(bigint b) const{ return b*=*this; }


    bigint& operator*=(base_t b){
	int j=1; base_t carry=(inner[0]*=b)/BASE; inner[0]%=BASE;
	while(carry!=0){carry=(inner[j]+=carry)/BASE; inner[j++]%=BASE;}
	if(j>used && inner[j-1]!=0) used=j;
	return *this;
    }
    bigint operator*(base_t b) const{ bigint r(*this); return r*=b; }
    

    bigint operator/(base_t d) const{ return div(d).first;}
    base_t operator%(base_t d) const{ return div(d).second;}

    pair<bigint,base_t> div (base_t d) const{
	if(d<BASE) throw std::exception();
	pair<bigint,base_t> r(*this,0);
	for(int i=used-1;i>=0;i--){
	    r.second=(r.first.inner[i]+=BASE*r.second)%BASE;
	    r.first.inner[i]/=BASE;
	}
	while(r.first.used && !r.first.inner[r.first.used-1]) 
	    --r.first.used;
	return r;
    }  

    string str() const{
	stringstream ss;
	ss << sign*inner[used-1];
	for(int i=used-2;i>=0;i--)
	    ss<<"00000000"+(int)(inner[i] ? floor(log10(inner[i])) : 0)
	      << inner[i];
	return ss.str();
    }

    char sign; //sign bit
    unsigned used; //number of base_t in used
    base_t inner[NUM]; //base array
};

bigint operator+(long long int i, const bigint& l){ return l+i; }
bigint operator*(long long int i,const bigint& l){ return l*i; }
bigint operator-(long long int i,const bigint& l){ return bigint(i)-l;}

pair<bigint, bigint> v[1001];

int main() {
	v[0].first = bigint(1);
	v[0].second = bigint(0);
	v[1].first = bigint(1);
	v[1].second = bigint(1);
	for (int i = 2; i <= 1000; i++) {
		v[i].first = bigint();
		v[i].second = bigint();
		if (i%2 == 0) {
			v[i].first = v[i-1].first + v[i-1].second;
			v[i].second = v[i-1].second;
		} else {
			v[i].first = v[i-1].first;
			v[i].second = v[i-1].second + v[i-1].first;
		}
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		cout << (v[n].first + v[n].second).str() << endl;
	}
	return 0;
}