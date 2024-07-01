#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int n, int m, vector<vector<pair<int, int>>>& graph) {
        vector<long long> dist(n + 1, LLONG_MAX);
        vector<bool> visited(n + 1, false);
        
        dist[1] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 1});
        
        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            
            if (visited[node]) continue;
            visited[node] = true;

            for (auto& it : graph[node]) {
                int next = it.first;
                long long weight = it.second;
                if (!visited[next] && dist[next] > dist[node] + weight) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }
        
        return dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
      
    }

    Solution solution;
    vector<long long> ans = solution.solve(n, m, graph);

    for (int i = 1; i <= n; ++i) {
        if (ans[i] == LLONG_MAX)
            cout << "INF ";
        else
            cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
