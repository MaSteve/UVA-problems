// las12uvas contest PROBLEM G 2015
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

char tonom(char c) {
	switch(c) {
		case '0': return 'O';
		case '1': return 'I';
		case '2': return 'Z';
		case '3': return 'E';
		case '4': return 'A';
		case '5': return 'S';
		case '6': return 'G';
		case '7': return 'T';
		case '8': return 'B';
		case '9': return 'P';
		default: return c;
	}
}

int main() {
    int cases;
	scanf("%d", &cases);
	string str;
	getline(cin, str);
	for (int i = 0; i < cases; i++) {
		while(getline(cin, str) && str != "") {
			transform(str.begin(), str.end(), str.begin(), tonom);
			cout << str << endl;
		}
		if (i != cases -1)cout << endl;
	}
    return 0;
}