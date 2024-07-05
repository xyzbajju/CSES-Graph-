//////////////////////////
This Solution Gives TLE on some cases moreOver I think that this Greedy (Dijkstra Approach would not work in this case)



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dist;
    vector<int> par;

    void path(vector<set<pair<int, int>>>& graph, int n, int m) {
        dist.resize(n, INT_MAX);
        par.resize(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int di = pq.top().first;
            pq.pop();
            if (dist[node] < di) continue;
            for (auto it : graph[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[v] > dist[node] + wt) {
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v], v});
                    par[v] = node;
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].insert({v - 1, -1});
    }
    Solution HARSH;
    HARSH.path(graph, n, m);
    if (HARSH.dist[n - 1] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << 1 + HARSH.dist[n - 1] * (-1) << endl;
        vector<int> ans;
        int buff = n - 1;
        while (buff != -1) {
            ans.push_back(buff);
            buff = HARSH.par[buff];
        }
        reverse(ans.begin(), ans.end());
        for (auto it : ans) {
            cout << it + 1 << " ";
        }
        cout << endl;
    }
}
