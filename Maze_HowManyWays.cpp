#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

ll mem[100][100];

// How many ways a rabbit can reach from point (n, m) to (1, 1) in a (n x m) grid
// Can move only to right and down
ll sols_count1(int n, int m) {
    for (int i=0; i<=n; i++) mem[i][1] = 1;
    for (int i=0; i<=m; i++) mem[1][i] = 1;

    for (int i=2; i<=n; i++) {
        for (int j=2; j<=m; j++) {
            mem[i][j] = mem[i-1][j] + mem[i][j-1];
        }
    }

    return mem[n][m];
}

// Memoization
ll sols_count2(int n, int m) {
    if (n == 1 or m == 1) return 1;

    if (mem[n][m]) return mem[n][m];

    mem[n][m] = sols_count2(n-1, m) + sols_count2(n, m-1);
    return mem[n][m];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cout << "Solutions Possible: " << sols_count2(75, 19) << endl;

    return 0;
}