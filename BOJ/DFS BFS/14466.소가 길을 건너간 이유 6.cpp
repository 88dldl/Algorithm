#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,k,r;

vector<pair<int,int>> cow;
int arr[101][101][4]={0,};
bool visit[101][101];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1}; 


void solve(int x, int y){
    int cnt=0;
    visit[x][y]=true;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy= q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            if(arr[nowx][nowy][i]==1) continue;
            
            int nextx = nowx+dx[i];
            int nexty = nowy+dy[i];
            
            if(nextx<=0 || nexty<=0 || nextx>n || nexty>n || visit[nextx][nexty]){
                continue;
            }
            
            visit[nextx][nexty]=true;
            q.push({nextx,nexty});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>k>>r;
    
    for(int i=0;i<r;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        
        for(int j=0;j<4;j++){ // 동서남북 저장 필요
            int nx = dx[j]+a;
            int ny = dy[j]+b;
            
            if(nx==c && ny==d){
                arr[a][b][j] = 1;
                arr[nx][ny][(j+2)%4]=1;
            }
        }
    }
    
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        cow.push_back({x,y});
    }
    
    int ans = 0;
    for(int i=0;i<k;i++){
		memset(visit, 0, sizeof(visit));
        solve(cow[i].first,cow[i].second);
        
        for(int j=i+1;j<k;j++){
            if (visit[cow[j].first][cow[j].second] == 0){
				ans++;
			}
        }
    }
    
    cout<<ans;
    return 0;
}