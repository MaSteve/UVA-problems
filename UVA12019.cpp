// las12uvas contest PROBLEM H 2015
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

string dayOfWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int dateToInt (int m, int d, int y){
	return
		1461*(y+4800+(m-14)/12)/4+
		367*(m -2-(m-14)/12*12)/12-
		3*((y+4900+(m-14)/12)/100)/4+
		d-32075;
}
string intToDay (int jd) { return dayOfWeek[jd%7]; }

int main() {
    int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int m, d;
		cin >> m >> d;
		cout << intToDay (dateToInt (m, d, 2011)) << endl;
	}
    return 0;
}