#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char v[5][5];
bool visit[25]={false};
bool check[5][5]={false};

int finsum=0;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

//인접 확인
bool abj(int index) {
    memset(check, 0, sizeof(check));

    queue<pair<int, int>> q;
    int count = 0;

    q.push({index/5,index% 5});
    check[index/5][index % 5] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        count++;

        if (count == 7) return true;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0 && ny < 5 && nx < 5 && visit[ny * 5 + nx]&& !check[ny][nx]) {
                q.push({ ny,nx });
                check[ny][nx] = true;
            }
            
        }
    }

    return false;
}

// 7개 골라내기
void dfs(int x,int cnt,int s) {
    if (cnt == 7) {
        if (s >= 4) {
            if (bfs(x)) finsum++;
        }
        return;
    }

    for (int i = x; i < 25; i++) {
        if (visit[i]) continue;
        visit[i] = true;
        dfs(i ,cnt + 1, s + (v[i/5][i%5] == 'S'));
        visit[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    
    dfs(0,0,0);
    cout<<finsum;
    return 0;
}