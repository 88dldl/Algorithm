#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r,c;
queue<pair<int,int>> fireq;
queue<pair<int,int>> q;

char maze[1001][1001];
int fDist[1001][1001];
int pDist[1001][1001];

int dx[4]={-1,0,1,0};
int dy[4] = {0,-1,0,1};

int solve(){
    while(!fireq.empty()){
        int nowx = fireq.front().first;
        int nowy = fireq.front().second;

        fireq.pop();
        
        for(int i=0;i<4;i++){
            int nextx= nowx+dx[i];
            int nexty = nowy+dy[i];
   
            if(nexty<0 || nextx<0 || nextx>=r || nexty>=c){
                continue;
            }
            if(fDist[nextx][nexty]!=0) {
                continue;
            }
            fireq.push({nextx,nexty});
            fDist[nextx][nexty] = fDist[nowx][nowy]+1;
        }
    }
    
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextx = nowx + dx[i];
            int nexty = nowy + dy[i];

            if (nexty < 0 || nextx < 0 || nextx >= r || nexty >= c ) {
                return pDist[nowx][nowy];
            }
            if (pDist[nextx][nexty] != 0)
                continue;
            if (pDist[nowx][nowy] + 1 >= fDist[nextx][nexty] && fDist[nextx][nexty] > 0)
                continue;

            q.push({nextx, nexty});
            pDist[nextx][nexty] = pDist[nowx][nowy] + 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>r>>c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='J'){
                q.push({i,j});
                pDist[i][j] = 1;
            }
            if(maze[i][j]=='F'){
                fireq.push({i,j});
                fDist[i][j] = 1;
            }
            if(maze[i][j]=='#'){
                pDist[i][j] = -1;
                fDist[i][j] = -1;
            }
        }
    }
    
    int ans = solve();
    if(ans==0){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<ans;
    return 0;
}