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
vt<int> adj[N];
int visited[N];
int dist = INT_MIN, nodeX;

void dfs(int node, int d = 0) {
    visited[node] = 1;
    if (d > dist) {
        dist = d;
        nodeX = node;
    }

    for (int child: adj[node]) {
        if (visited[child] == 0) dfs(child, d+1);
    }
}

void solve(int n) {
    dfs(1); // start from any arbitrary node
    dist = INT_MIN;
    memset(visited, 0, sizeof(visited));

    dfs(nodeX);

    // dfs is linear time
    // complexty = 2 * dfs = O(n)

    cout << "Diameter: " << dist << endl;
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

    solve(n);

    return 0;
}

// 8 7
// 1 2
// 2 3
// 3 7
// 2 4
// 4 6
// 4 5
// 7 8