#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const int N = 1e4;
vt<int> adj[N], tr[N], scc[N], out;
int visited[N], idx;

void dfs1(int node) {
    visited[node] = 1;

    for (int nb: adj[node]) {
        if (visited[nb] == 0) {
            dfs1(nb);

            out.pb(nb);
        }
    }
}

void dfs2(int node) {
    visited[node] = 1;
    scc[idx].pb(node);

    for (int nb: tr[node]) {
        if (visited[nb] == 0) dfs2(nb);
    }
}

void solve(int n) {
    // In condensation graph, node with the highest out-time has the lowest in-time 0, so start interating from a node with highest outdegree from the transpose graph [that way to leak path would be made out of the SCCs]    
    for (int i=1; i<=n; i++) {
        if (visited[i] == 0) {
            dfs1(i);
            out.pb(i);
        }
    }

    memset(visited, 0, sizeof(visited));
    reverse(out.begin(), out.end());
    for (int node: out) {
        if (visited[node] == 0) dfs2(node), idx++;
    }
    for (int i=0; i<idx; i++) {
        cout << "Component-" << (i+1) << ": "; 
        for (int node: scc[i])
            cout << node << ' ';
        cout << endl;
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
        adj[a].pb(b); // edge from a to b
        tr[b].pb(a); // transpose graph
    }

    solve(n);

    return 0;
}
// 7 8
// 1 2
// 2 3
// 3 1
// 2 4
// 4 6
// 6 7
// 7 5
// 5 6