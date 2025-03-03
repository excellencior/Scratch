#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const int N = 1e5;
ll mem[N];

ll fib(ll n) {
    if (n <= 2) return 1;

    if (mem[n]) return mem[n];

    mem[n] = fib(n-1) + fib(n-2);
    return mem[n];
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cout << fib(7) << endl;
    cout << fib(50) << endl;

    return 0;
}