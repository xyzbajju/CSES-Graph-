#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int start = -1, end = -1;
   
    bool dfs(int node, vector<int>& par, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                par[it] = node;
                if (dfs(it, par, graph, vis, pathVis)) {
                    return true;
                }
            } else if (pathVis[it]) {
                start = it;
                end = node;
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

    vector<int> trip(vector<vector<int>>& edges, int n, int m) {
        vector<vector<int>> graph(n);
        for (auto it : edges) {
            graph[it[0] - 1].push_back(it[1] - 1); 
        }
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> par(n, -1);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, par, graph, vis, pathVis)) break;
            }
        }

        vector<int> ans;
        if (start == -1) return ans;
        else {
            ans.push_back(start + 1);
            int buff = end;
            while (buff != start) {
                ans.push_back(buff + 1);
                buff = par[buff];
            }
            ans.push_back(start + 1);
            reverse(ans.begin(), ans.end());
        }
        return ans;
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
    vector<int> ans = sol.trip(edges, n, m);
    if (ans.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans.size() << endl;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
