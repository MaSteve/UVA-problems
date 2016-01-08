// las12uvas contest PROBLEM A 2015
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>
#include <cctype>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {

    unordered_map<int, int> map;
    
    vector<string> vec;
    vector<int> per;
    int cases;
	scanf("%d", &cases);
	string c;
	getline(cin, c);
	for (int i = 0; i < cases; i++) {
		per.clear();
		vec.clear();
		map.clear();
		int max = 0;
		int k = 0;
		getline(cin, c);
		if (i != 0) getline(cin, c);
		while(cin.peek() != '\n'){
			int l;
			cin >> l;
			if(l>max) max = l;
			per.push_back(l);
			map.insert(pair<int, int>(l, k));
			k++;
		}
		for(int j = 0; j < max; j++){
			string f;
			cin >> f;
			vec.push_back(f);
		}
		for(int j = 0; j < max; j++){
			cout << vec[map[j+1]] << endl;
		}
		if(i != cases -1)cout << endl;
	}
    return 0;
}