#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int pivot = -1;
        for (int i = 1; i <= n; ++i) {
            if (adj[i].size() == 2) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            cout << "NO\n";
            continue;
        }

        int u = adj[pivot][0];
        int v = adj[pivot][1];

        vector<pair<int, int>> edges;
        vector<bool> visited(n + 1, false);
        queue<int> q;

        // Direct edges from u to pivot and pivot to v
        edges.emplace_back(u, pivot);
        edges.emplace_back(pivot, v);
        visited[pivot] = true;
        visited[u] = true;
        visited[v] = true;

        // BFS from u to direct edges away from u
        q.push(u);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int neighbor : adj[current]) {
                if (!visited[neighbor] && neighbor != pivot) {
                    edges.emplace_back(current, neighbor);
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // BFS from v to direct edges towards v
        q.push(v);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int neighbor : adj[current]) {
                if (!visited[neighbor] && neighbor != pivot) {
                    edges.emplace_back(neighbor, current);
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        if (edges.size() != n - 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (auto [a, b] : edges) {
            cout << a << " " << b << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}