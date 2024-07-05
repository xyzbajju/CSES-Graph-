#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> Reverse_graph;
vector<int> dp;
vector<int> indegree;
int n, m;
const int mod = 1e9+7;

class Solution {
public:
    int ways() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        dp.resize(n, 0);
        dp[0] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
            for (auto it : Reverse_graph[node]) {
                dp[node] = (dp[node] + dp[it]) % mod;
            }
        }
        return dp[n - 1];
    }
};

int main() {
    cin >> n >> m; 
    graph.resize(n);
    Reverse_graph.resize(n);
    indegree.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; 
        graph[a].push_back(b);
        Reverse_graph[b].push_back(a);
        indegree[b]++;
    }
    Solution HARSH;
    cout << HARSH.ways() << endl;
}
