#include <iostream>
using namespace std;

int n,m;
int road[500][500],dp[500][500];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

int solve(int x,int y){
    if(x==n-1 && y==m-1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    
    dp[x][y]=0;
    
    for(int i=0;i<4;i++){
        int nextx = x+dx[i];
        int nexty = y+dy[i];
        if(nextx>=0 && nexty>=0 && nextx<n && nexty<m && road[nextx][nexty]<road[x][y]){
            dp[x][y] += solve(nextx,nexty);
        }
    }
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(NULL);

    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>road[i][j];
            dp[i][j]=-1;
        }
    }
    
    cout<<solve(0,0);

    return 0;
}