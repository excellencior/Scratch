// Bottom-up approach


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
    for (int i=0; i<=amount; i++) mem[i] = INT_MAX;

    mem[0] = 0;
    for (int i=1; i<=amount; i++) {
        for (int coin: coins) {
            int rem = i - coin;

            if (rem < 0) continue;

            mem[i] = min(mem[i], mem[rem] + 1);
        }
    }

    return mem[amount];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    coins = vt<int>({1, 4, 5});
    int amount = 150;
    cout << "Total amount: " << amount << endl;
    cout << "Total coins: " << coin_count(amount) << endl;

    return 0;
}