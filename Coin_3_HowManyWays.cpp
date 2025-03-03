// Memoization
// Top-Down Approach

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const int N = 1e5;
int mem[N];
vt<int> coins;

// How many ways we can reach to amount 0
int sols_count(int amount) {
    if (amount == 0) return 1; // One way to solve is to take no coin
    if (mem[amount]) return mem[amount];

    for (int coin: coins) {
        int rem = amount - coin;

        if (rem < 0) continue;

        mem[amount] += sols_count(rem);
    }

    return mem[amount];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    coins = vt<int>({1, 4, 5});
    int amount = 5;
    cout << "Total amount: " << amount << endl;
    cout << "Total solutions: " << sols_count(amount) << endl;

    return 0;
}
// 5
// 1 + 4
// 4 + 1
// 1 + 1 + 1 + 1 + 1