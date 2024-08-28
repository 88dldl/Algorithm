#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 987654321

int n,m,a,b,last;
int cnt[101], parent[101];
vector<int> v[100001], e[101];

int bfs() {
    int mn = INF;
    queue<int> q;

    for (int i = 0; i < v[a].size(); i++) {
        bool check = false;

        for (int j = 0; j < v[b].size(); j++) {
            if (v[a][i] == v[b][j]) check = true;
        }

        if (check) { 
            last = v[a][i];
            return mn = 1;
        } else {
            cnt[v[a][i]] = 1;
            q.push(v[a][i]);
        }
    }

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        for (int i = 0; i < e[tmp].size(); i++) {
            int now = e[tmp][i];

            if (now == b) {
                last = tmp;
                return cnt[tmp];
            }

            for (int j = 0; j < v[now].size(); j++) {
                int nextElevator = v[now][j];

                if (cnt[nextElevator] == 0) {  // 아직 방문하지 않은 엘리베이터
                    cnt[nextElevator] = cnt[tmp] + 1;
                    parent[nextElevator] = tmp;
                    q.push(nextElevator);
                }
            }
        }
    }

    return mn;
}

void printans(int x) {
    if (x == 0) return;
    printans(parent[x]);
    cout << x << "\n";
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        while (x <= n) {
            v[x].push_back(i);  
            e[i].push_back(x); 
            x += y;
        }
    }
    
    memset(parent, 0, sizeof(parent));
    memset(cnt, 0, sizeof(cnt));
    
    cin >> a >> b;
    int ans = bfs();

    if (ans >= INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
        printans(last);
    }

    return 0;
}
