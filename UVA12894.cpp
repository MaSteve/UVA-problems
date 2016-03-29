// las12uvas contest PROBLEM J 2015
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

float pi = acos(-1);

int main() {
    int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		bool ok = true;
		float x0, y0, x1, y1, cx, cy, r;

		cin >> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;

		if((x1-x0)/(y1-y0)!= (10.0f/6.0f))ok = false;
		if((x1-x0)/r != 5.0f) ok = false;
		if((x1-x0)/(cx-x0) != (10.0f/4.5f)) ok = false;
		if((y1-y0)/(cy-y0) != 2.0f) ok = false;

		if (ok) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}