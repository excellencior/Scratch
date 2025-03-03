// From cp-algorithms

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
int visited[N], in[N], low[N], timer;

void dfs(int node, int parent) {
    visited[node] = 1;
    in[node] = low[node] = timer;
    timer++;

    for (int child: adj[node]) {
        if (child == parent) continue;
    
        if (visited[child] == 1) {
            // Not parent but visited = back edge (two ways to get to a node)
            low[node] = min(low[node], in[child]);
        }
        else {
            dfs(child, node);

            // Backtracing here
            // Forward Edge
            if (low[child] > low[node]) cout << node << " - " << child << " is a bridge" << endl;
            // Update low[node]
            // If there is another path to child, then there is also another path to node
            // Update this information from child to node
            low[node] = min(low[node], low[child]);
        }
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

    dfs(1, -1);

    return 0;
}