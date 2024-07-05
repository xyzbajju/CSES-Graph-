////////////////////////////////
Normal Dijkstra with keeping track of the ways and minCities and maxcities;



#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
const ll mod = 1e9 + 7;

class Solution {
public:
    vector<ll> calculate(int n, int m, vector<pair<int, pair<int, int>>>& edges) {
        vector<vector<pair<ll, ll>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i].first;
            int v = edges[i].second.first;
            int w = edges[i].second.second;
            adj[u].push_back({v, w});
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);
        vector<ll> minc(n, LLONG_MAX);
        vector<ll> maxc(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        minc[0] = 0;
        maxc[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto z = pq.top();
            pq.pop();
            ll u = z.second;
            ll w = z.first;
            if (dist[u] < w) continue;

            for (auto &i : adj[u]) {
                ll v = i.first;
                ll weight = i.second;
                if (dist[v] > w + weight) {
                    dist[v] = w + weight;
                    ways[v] = ways[u];
                    minc[v] = minc[u] + 1;
                    maxc[v] = maxc[u] + 1;
                    pq.push({dist[v], v});
                } else if (dist[v] == w + weight) {
                    ways[v] += ways[u];
                    ways[v] %= mod;
                    minc[v] = min(minc[v], minc[u] + 1);
                    maxc[v] = max(maxc[v], maxc[u] + 1);
                }
            }
        }

        return {dist[n - 1], ways[n - 1], minc[n - 1], maxc[n - 1]};
    }
};

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u - 1, {v - 1, w}};
    }

    Solution sol;
    vector<ll> result = sol.calculate(n, m, edges);
    cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << endl;
}
