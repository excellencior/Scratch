#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

void solve(string str, int k) {
    ll count1 = 0, count2 = 0, moves = 0, i = 0;

    string max_val = "";
    while (true) {
        if (max_val < str) {
            max_val = str;
            count1 = i;
        }
        else if (max_val == str) {
            count2 = i;
            break;
        }
        i++;
        string temp = str.substr(1, str.size() - 1);
        str = temp + str[0];
    }

    cout << count1 + (count2 - count1) * (k-1) << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    fstream cin("input");
    int t, n;
    ll k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> str;

        solve(str, k);
    }

    return 0;
}