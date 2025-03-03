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
vt<int> adj[N], nodes;
int visited[N], subSize[N];

void dfs(int node) {
    visited[node] = 1;
    int curr_size = 1;

    for (int child: adj[node]) {
        if (visited[child] == 0) {
            dfs(child);
            curr_size += subSize[child];
        }
    }

    subSize[node] = curr_size;
}

void solve(int n) {
    // Preprocessing all the subtree's sizes
    dfs(1); // nodes from 1 to n

    for (int node: nodes) {
        cout << "Subtree size > " << node << " --> " << subSize[node] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    fstream cin("input");

    int n, m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    int t;
    cin >> t;
    while(t--) {
        cin >> a;
        nodes.pb(a);
    }

    solve(n);

    return 0;
}

// 7 6
// 1 2
// 2 3
// 3 7
// 2 4
// 4 6
// 4 5
// 4
// 1
// 2
// 4
// 3