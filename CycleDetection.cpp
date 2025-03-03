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

bool dfs(int node, int parent = -1) {
    visited[node] = 1;
    
    for (int child: adj[node]) {
        if (visited[child] == 0) {
            if (dfs(child, node) == true) return true;
        }
        else {
            if (child != parent) return true;
        }
    }
    return false;
}

void solve() {
    if (dfs(1)) cout << "Cycle exists" << endl;
    else cout << "No cycle is found" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    fstream cin("input");
    int n, m, a, b;
    cin >> n >> m;
    
    while (m--) {
        cin >> a >> b;
    
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve();

    return 0;
}

// 5 5
// 1 2
// 2 3
// 3 4
// 2 4
// 4 5