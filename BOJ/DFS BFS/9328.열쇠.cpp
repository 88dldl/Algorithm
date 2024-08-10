#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int h,w,maxnum;
bool key[26]; 
bool visit[102][102];
char v[102][102];

int dy[4] = {1,0,-1,0};
int dx[4] = {0,-1,0,1};


void bfs(int x,int y){
    queue<pair<int,int>> q;
    queue<pair<int,int>> door[26];
    q.push(make_pair(x,y));

    visit[x][y] = true;
    
    while(!q.empty()){
        int tmpx = q.front().first;
        int tmpy = q.front().second;
        
        q.pop();

        for(int i=0;i<4;i++){
            int nx = tmpx + dx[i];
            int ny = tmpy + dy[i];
            
            if(nx<0 ||nx>h+1|| ny<0 || ny>w+1 ) continue;
            if(v[nx][ny] =='*' || visit[nx][ny]) continue ;
            
            visit[nx][ny] = true;
            
            // 대문자 
            if(v[nx][ny]>='A' && v[nx][ny]<='Z'){
                if(key[v[nx][ny]-'A']) q.push(make_pair(nx,ny)); // 키 보유
                else door[v[nx][ny]-'A'].push(make_pair(nx,ny)); // 없으면 문 위치 기억 
            }
            // 소문자 
            else if(v[nx][ny]>='a' && v[nx][ny]<='z'){
                q.push(make_pair(nx,ny)); // 키 보유
                if(!key[v[nx][ny]-'a']){
                    key[v[nx][ny]-'a'] = true;
                    // 키를 찾았으니까 이동가능
                    while(!door[v[nx][ny]-'a'].empty()){
                        q.push(door[v[nx][ny]-'a'].front());
                        door[v[nx][ny]-'a'].pop();
                    }
                }
            }
            else{
                q.push(make_pair(nx,ny));
                if(v[nx][ny]=='$') maxnum++;
            }
        }
        
    }
}
        
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        memset(key,false,sizeof(key));
        memset(visit,false,sizeof(visit));
        memset(v,0,sizeof(v));
        maxnum = 0;

        cin>>h>>w;
        
        //지도
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin>>v[i][j];
            }
        }

        //키
        string num;
        cin>>num;
        for (int i = 0; i < num.length(); i++) {
            if(num[i]=='0') continue;    
            key[num[i] - 'a'] = true;
        }

        bfs(0,0);

        cout<<maxnum<<"\n"; 
    }

    return 0;
}