#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> graph[MAXN];
int dp[MAXN], next_node[MAXN];
bool vis[MAXN];

int dfs(int node) {
    vis[node] = true;
    if (dp[node] != -1) {
        return dp[node];
    }
    int max_len = -1;
    for (int it : graph[node]) {
        if (!vis[it]) {
            dfs(it);
        }
        if (dp[it] != -1 && dp[it] + 1 > max_len) {
            max_len = dp[it] + 1;
            next_node[node] = it;
        }
    }
    return dp[node] = max_len;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
    }
    dp[n] = 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(1);

    if (dp[1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dp[1] << endl;
        int node = 1;
        while (node) {
            cout << node << " ";
            node = next_node[node];
        }
    }

    return 0;
}
