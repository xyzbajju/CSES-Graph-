#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> delR = {-1, 1, 0, 0};
    vector<int> delC = {0, 0, -1, 1};
    vector<char> directions = {'D', 'U', 'R', 'L'};

    vector<vector<int>> bfs(vector<pair<int, int>>& startPoints, vector<vector<char>>& grid, int n, int m) {
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        for (auto [x, y] : startPoints) {
            q.push({0, {x, y}});
            dist[x][y] = 0;
        }

        while (!q.empty()) {
            int di = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int new_X = x + delR[k];
                int new_Y = y + delC[k];

                if (new_X >= 0 && new_Y >= 0 && new_X < n && new_Y < m && grid[new_X][new_Y] != '#' && dist[new_X][new_Y] == INT_MAX) {
                    dist[new_X][new_Y] = di + 1;
                    q.push({dist[new_X][new_Y], {new_X, new_Y}});
                }
            }
        }

        return dist;
    }

public:
    void solve() {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        vector<pair<int, int>> startPoints, monsterPoints;
        pair<int, int> start;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'A') {
                    start = {i, j};
                    startPoints.push_back(start);
                } else if (grid[i][j] == 'M') {
                    monsterPoints.push_back({i, j});
                }
            }
        }

        vector<vector<int>> monsterDist = bfs(monsterPoints, grid, n, m);
        vector<vector<int>> startDist = bfs(startPoints, grid, n, m);

        int x, y;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && monsterDist[i][j] > startDist[i][j]) {
                    x = i;
                    y = j;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (!flag) {
            cout << "NO" << endl;
            return;
        }

        cout << "YES" << endl;

        string path;
        while (make_pair(x, y) != start) {
            for (int k = 0; k < 4; k++) {
                int dx = delR[k], dy = delC[k];
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && startDist[nx][ny] == startDist[x][y] - 1) {
                    path.push_back(directions[k]);
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }

        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    }
};

int main() {
    Solution Bajaj;
    Bajaj.solve();
    return 0;
}
