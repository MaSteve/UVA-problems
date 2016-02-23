// las12uvas contest PROBLEM E 2015
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

bool isvoc(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u';
}

int main() {
    string str1, str2;
    int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		cin >> str1 >> str2;
		bool ok = true;
		if (str1.length() != str2.length()) ok = false;
		str1.erase(remove_if(str1.begin(), str1.end(), isvoc), str1.end());
		str2.erase(remove_if(str2.begin(), str2.end(), isvoc), str2.end());
		if(str1 != str2) ok = false;
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}