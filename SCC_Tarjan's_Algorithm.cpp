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
vt<int> adj[N];
int visited[N], in[N], low[N], inStack[N], timer;
stack<int> discovered;

void dfs(int node) {
    visited[node] = 1;
    in[node] = low[node] = timer++;
    discovered.push(node);
    inStack[node] = 1;

    for (int nb: adj[node]) {
        // If the node is visited and in stack, then it maybe on the current searching component
        // If it's not in the stack, then it might be part of another component already found
        if (visited[nb] and inStack[nb]) {
            low[node] = min(low[node], in[nb]);
        }
        else if (visited[nb] == 0) {
            dfs(nb);

            if (inStack[nb]) {
                low[node] = min(low[node], low[nb]);
            }
        }
    }
    // Now nowhere to go => out-degree = 0
    // Came back at the node through a path different than the starting one
    // and isnot able to move further
    // if it can move futher then as the low[node] gets updated, this condition would be false
    if (in[node] == low[node]) {
        cout << "Component Found: ";
        int t;
        while (true) {
            t = discovered.top();
            discovered.pop();
            inStack[t] = 0;
            cout << t << ' ';

            if (t == node) break;
        }
        cout << endl;
    }
}

void solve(int n) {
    for (int i=1; i<=n; i++) {
        if (visited[i] == 0) dfs(i);
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
    }
    solve(n);

    return 0;
}


// 8 12
// 3 1
// 1 2
// 2 3
// 2 4
// 1 5
// 4 5
// 5 4
// 8 5
// 6 4
// 8 6
// 7 8
// 6 7