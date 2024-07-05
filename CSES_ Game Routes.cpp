#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, mod = 1e9+7;
    vector<int> dp;

    int dfs(int node, vector<int>& vis, vector<vector<int>>& graph) {
        vis[node] = 1;
        if (node == n - 1) {
            dp[node] = 1;
            vis[node] = 2;
            return dp[node];
        }

        for (auto it : graph[node]) {
            if (!vis[it]) {
                dfs(it, vis, graph);
            }
            dp[node] += dp[it];
            dp[node] %= mod;
        }
        vis[node] = 2;
        return dp[node];
    }

    int Ways(vector<vector<int>> edges, int n, int m) {
        this->n = n;
        vector<vector<int>> graph(n);
        for (auto it : edges) {
            graph[it[0]-1].push_back(it[1]-1);
        }
        vector<int> vis(n, 0);
        dp.resize(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, graph);
            }
        }

        return dp[0]; 
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    cout << sol.Ways(edges, n, m) << endl;
    return 0;
}
