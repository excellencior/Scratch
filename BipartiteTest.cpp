// BUGLIFE (spoj)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const int N = 1000001;
vt<int> adj[N];
int color[2001], visited[2001];

bool dfs(int node, int col = 0) {
    color[node] = col;
    visited[node] = 1;

    // Do a bipartite test
    for (int child: adj[node]) {
        if (visited[child] == 0) {
            if (dfs(child, ~col) == false) return false;
        }
        else {
            if (color[node] == color[child]) return false;
        }
    }
    return true;
}

void solve(int n, int scenario) {
    bool check = true;
    for (int i=1; i<=n; i++) {
        if (visited[i] == 0){
            bool res = dfs(i);
            // Why take res in middle?
            // graph-1 : false
            // graph-2 : true (overwrite)
            // Should be false if a single false is found
            if (res == false) check = false;
        } 
    }

    cout << "Scenario #" << scenario << ":" << endl;

    if (!check) cout << "Suspicious bugs found!" << endl;
    else cout << "No suspicious bugs found!" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // fstream cin("input");

    int t, n, e, a, b;
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> e;
        while (e--) {
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        solve(n, i);
        for (int i=0; i<=N; i++) adj[i].clear();
        memset(color, 0, sizeof(color));
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}

// 2
// 3 3
// 1 2
// 2 3
// 1 3
// 4 2
// 1 2
// 3 4