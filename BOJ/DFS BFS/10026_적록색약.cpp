#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

char grb[101][101];
char grb2[101][101];

int n,count=0;
int check[101][101]={0};
int check1[101][101]={0};

int dx[4]={1,0,-1,0};
int dy[4] = {0,-1,0,1};

queue<char> qdata;

void bfs(int x,int y,char data){
    check[x][y]=1;
    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    
    
    //qdata 큐에 RGB데이터 값 넣고 비교
    if(qdata.size()==0 || qdata.back()!=data ){ 
        qdata.push(data);
        count++;
    }

    while(!q.empty()){   
        int x=q.front().first;
        int y=q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int tmpx=x+dx[i];
            int tmpy=y+dy[i];
            if(tmpx>=0 && tmpy>=0  && tmpx<n && tmpy<n){ //tmpx와 tmpy가 범위 안에 있을 때
                if(grb[tmpx][tmpy]==qdata.back()&& check[tmpx][tmpy]==0){ //한번도 방문하지 않았고 gdata에 넣은 데이터 값과 같을때 
                    check[tmpx][tmpy]=1;   
                    q.push(make_pair(tmpx, tmpy));
                }
            }
        }
    }
    qdata.pop(); 
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin>>n;
    
    //적록색맹이 아닐 경우 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grb[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==0){
                bfs(i,j,grb[i][j]);
            }
        }
    }
    cout<<count<<" ";    

    //초기화 - 적록색맹일 경우   
    memset(check,0,sizeof(check));
    count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grb[i][j]=='R'){
                grb[i][j]='G';
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==0){
                bfs(i,j,grb[i][j]);
            }
        }
    }

    cout<<count;
    
    return 0;
}