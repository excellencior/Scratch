// a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime.
// from a 4-digit prime number to another 4-digit prime number along a path which consists only of prime numbers of 4-digit

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
int visited[N], dist[N];
vt<int> adj[N], primes; // primes = stores all the 4-digit prime numbers

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i=2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Check if the two numbers can be adjacent == Difference in digit should be atmost 1
bool can_connect(int a, int b) {
    int cnt = 0;
    while (a or b) {
        if (a%10 != b%10) cnt++;
        a /= 10;
        b /= 10;
    }
    if (cnt == 1) return true;
    return false;
}

void create_graph() {
    for (int i=1000; i<=9999; i++) {
        if (is_prime(i)) primes.pb(i);
    }

    int a, b;
    for (int i=0; i<primes.size(); i++) {
        for (int j=i+1; j<primes.size(); j++) {
            a = primes[i];
            b = primes[j];

            if (can_connect(a, b)) {
                adj[a].pb(b);
                adj[b].pb(a);
            }
        }
    }
}

void bfs(int from, int to) {
    std::queue<int> q;

    int curr_node = from;
    q.push(curr_node);
    visited[curr_node] = 1;

    while (!q.empty()) {
        curr_node = q.front();
        q.pop();

        for (int nb: adj[curr_node]) {
            if (visited[nb] == 0) {
                visited[nb] = 1;
                dist[nb] = dist[curr_node] + 1;
                q.push(nb);

                if (nb == to) return;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    fstream cin("input");

    // Preprocessing
    create_graph();

    int t, a, b;

    cin >> t;
    while (t--) {
        cin >> a >> b;

        bfs(a, b); // Check if there is path from a to b (dfs would be costly here, much more nodes visited)

        if (visited[b] == 0) cout << "Impossible" << endl;
        else cout << dist[b] << endl;

        memset(dist, 0, sizeof(dist));
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}