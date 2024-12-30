#include <iostream>
#include <queue>
using namespace std;

int k, w, h;
int map[201][201];
bool visit[201][201][31];

int horseDx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int horseDy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Info {
    int x, y, count, horseMoves;
};

void solve() {
    queue<Info> q;
    q.push({0, 0, 0, 0});
    visit[0][0][0] = true;

    while (!q.empty()) {
        int nowx = q.front().x;
        int nowy = q.front().y;
        int count = q.front().count;
        int horseMoves = q.front().horseMoves;
        q.pop();

        if (nowx == h - 1 && nowy == w - 1) {
            cout << count << "\n";
            return;
        }

        if (horseMoves < k) {
            for (int i = 0; i < 8; i++) {
                int nextx = nowx + horseDx[i];
                int nexty = nowy + horseDy[i];

                if (nextx < 0 || nexty < 0 || nextx >= h || nexty >= w || map[nextx][nexty] || visit[nextx][nexty][horseMoves + 1]) {
                    continue;
                }

                visit[nextx][nexty][horseMoves + 1] = true;
                q.push({nextx, nexty, count + 1, horseMoves + 1});
            }
        }

        for (int i = 0; i < 4; i++) {
            int nextx = nowx + dx[i];
            int nexty = nowy + dy[i];

            if (nextx < 0 || nexty < 0 || nextx >= h || nexty >= w || map[nextx][nexty] || visit[nextx][nexty][horseMoves]) {
                continue;
            }

            visit[nextx][nexty][horseMoves] = true;
            q.push({nextx, nexty, count + 1, horseMoves});
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }

    solve();
    return 0;
}
