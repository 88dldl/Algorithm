#include <iostream>
#include <cstring>
using namespace std;

int t,n;
int parent[10001]={0};
bool visit[10001]={false};

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>t;
    while(t--){
        memset(visit,false,sizeof(visit));
        memset(parent,-1,sizeof(parent));
        
        cin>>n;
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            parent[y]=x;
        }
        
        int nx,ny;
        cin>>nx>>ny;
        //x 루트까지 보내기
        while(nx!=-1){
            visit[nx]=true;
            nx=parent[nx];
        }
        //방문한 곳이라면 cout 
        while(true){
            if(visit[ny]){
                cout<<ny<<"\n";
                break;
            }
            ny=parent[ny];
        }
    }
    return 0;
}