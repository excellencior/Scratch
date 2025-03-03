// Memoization
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

int coin_count(int amount) {
    if (amount == 0) return 0;
    if (mem[amount]) return mem[amount];

    int ans = INT_MAX;
    for (int coin : coins) {
        int rem = amount - coin;
        if (rem < 0) continue;

        ans = min(ans, coin_count(rem) + 1);
    }
    mem[amount] = ans;
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    coins = vt<int>({1, 4, 5});
    int amount = 150;

    cout << "Total amount: " << amount << endl;
    cout << "Coins required: " << coin_count(amount) << endl;

    return 0;
}