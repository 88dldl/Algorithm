#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> v[1001];
int d[1001], ind[1001], dp[1001];
int n, k, w;

void solve() {
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            dp[i] = d[i];
        }
    }
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            dp[next] = max(dp[next], dp[now] + d[next]);
            if (--ind[next] == 0) {
                q.push(next);
            }
        }
    }
    
    cout << dp[w] << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(d, 0, sizeof(d));
        memset(ind, 0, sizeof(ind));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) v[i].clear();
        
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            ind[y]++;
        }
        
        cin >> w;
        solve();
    }

    return 0;
}
