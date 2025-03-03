#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const int N = 1e5;
int visited[N], dist[N];

vt<int> adj[N];

// Print the distance from the selected node to all other nodes (shortest dist)
void solve(int sel_node, int n)
{
    std::queue<int> q;

    int curr_node;
    visited[sel_node] = 1;
    q.push(sel_node);

    while (!q.empty())
    {
        curr_node = q.front();
        q.pop();
        for (int nb : adj[curr_node])
        {
            // if the neightbour is not visited then update the distance to that neightbour
            if (visited[nb] == 0) {
                dist[nb] = dist[curr_node] + 1;
                visited[nb] = 1;
                q.push(nb);
            }
        }
    }

    cout << "Distances" << endl;
    cout << "----------" << endl;
    for (int i=1; i<=n; i++) {
        cout << "Distance to node " << i << " from node " << sel_node << " : " << dist[i] << endl;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    fstream cin("input");

    int a, b, n, m;
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    int sel_node;
    cin >> sel_node;

    solve(sel_node, n); // Selected Node, total number of nodes (1..n  )

    return 0;
}

// 7 8
// 1 2
// 2 4
// 1 3
// 2 3
// 3 5
// 5 6
// 6 7
// 5 7
// 3