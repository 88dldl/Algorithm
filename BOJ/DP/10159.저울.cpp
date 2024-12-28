#include <iostream>
using namespace std;

int map[101][101];
int n,m;

void solve(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][k]==map[k][j] && map[i][k]!=0){
                    map[i][j]=map[i][k];
                }
            }
        }
    }   
    for(int i=1;i<=n;i++){
        int count=n-1;
        for(int j=1;j<=n;j++){
            if(map[i][j]!=0) count--;
        }
        cout<<count<<'\n';
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a][b]=1;
        map[b][a]=-1;
    }
    solve();
    return 0;
}