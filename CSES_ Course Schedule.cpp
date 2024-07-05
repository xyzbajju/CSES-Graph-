#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis, stack<int>& st, bool& hasCycle) {
        vis[node] = 1; 
        for (auto it : graph[node]) {
            if (vis[it] == 0) {
                dfs(it, graph, vis, st, hasCycle);
            } else if (vis[it] == 1) {
                hasCycle = true;
                return;
            }
        }
        vis[node] = 2; 
        st.push(node);
    }

    bool topo(vector<vector<int>>& edges, int n, stack<int>& st) {
        vector<vector<int>> graph(n);
        for (auto it : edges) {
            graph[it[0] - 1].push_back(it[1] - 1); 
        }
        vector<int> vis(n, 0);
        bool hasCycle = false;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, graph, vis, st, hasCycle);
                if (hasCycle) return false;
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution obj;
    stack<int> ans;
    if (obj.topo(edges, n, ans)) {
        vector<int> result;
        while (!ans.empty()) {
            result.push_back(ans.top() + 1); 
            ans.pop();
        }
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
