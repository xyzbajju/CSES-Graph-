#include <bits/stdc++.h>
using namespace std;

int main() {
     int n;
    cin >> n;
    vector<int> nextnode(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nextnode[i];
    }

    vector<int> vis(n + 1, 0);
    vector<int> answer(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            unordered_set<int> tempset;
            vector<int> tempvec;
            int x = i;
            bool flag = true;

            while (tempset.find(x) == tempset.end()) {
                tempset.insert(x);
                tempvec.push_back(x);
                if (vis[x]) {
                    flag = false;
                    break;
                }
                x = nextnode[x];
            }

            int z = find(tempvec.begin(), tempvec.end(), x) - tempvec.begin();
            int m = tempvec.size();

            for (int j = z; j < m; j++) {
                vis[tempvec[j]] = 1;
                if (answer[tempvec[j]] == -1)
                    answer[tempvec[j]] = m - z;
            }

            for (int j = z - 1; j >= 0; j--) {
                vis[tempvec[j]] = 1;
                if (answer[tempvec[j]] == -1)
                    answer[tempvec[j]] = answer[tempvec[j + 1]] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }


}
