#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

vt<int> arr;

void solve(int n)
{
    int sidx, eidx;
    bool starti, endi;
    
    while (true)
    {
        starti = endi = false;
        sidx = eidx = -1; // Reset indices
        
        for (int i = 0; i < n - 1; i++) // Update loop condition to avoid out of bounds access
        {
            if (arr[i] > arr[i + 1] && starti == false)
            {
                sidx = i;
                starti = true;
            }
            else if (arr[i] <= arr[i + 1] && starti == true && endi == false)
            {
                eidx = i;
                endi = true;
            }
        }

        if (starti == false && endi == false) break;
        
        // end index not found means the data is reversed till the last element
        if (endi == false) eidx = n - 1;
        
        // Sort the array segment [sidx, eidx] using reverse
        reverse(arr.begin() + sidx, arr.begin() + eidx + 1);

        // Print every state of the array
        for (int i=0; i<n; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(n);

    return 0;
}


// 10
// 5 1 4 3 2 6 7 8 9 10