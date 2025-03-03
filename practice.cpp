#include <bits/stdc++.h>
using namespace std;


vector<int> a, b;

void shift(int idx) {	
	for (int i=idx + 1; i<a.size(); i++) {
		a[i] = a[idx-1];
	}
}

void solve() {
	int i=0, check = false, count = 0;
	while (i<a.size()) {
		if (a[i] > b[i]) {
			a[i] = b[i];
			shift(i);
			count++;
		}
  	}
  	cout << count << endl;
}

int main() {
//	fstream cin("input");
	int t, n, d;
	 
	cin >> t;
	
	while (t--) {
		cin >> n;
		
		while (n--) {
			cin >> d;
			a.push_back(d);
			b.push_back(d);
		}
		
		solve();
	}
	
	return 0;
}
