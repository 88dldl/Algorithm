#include <iostream>

using namespace std;
int n,m;
int arr[8];
int visit[8]={0};

void bfs(int x,int num){
    if(num==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<"\n";
        return;
    }
    
    for(int i=x;i<=n;i++){ 
        if(visit[i]==0){
            visit[i]=1;
            arr[num]=i;
            bfs(i,num+1);
            visit[i]=0;
        }
    }
}

int main()
{
    cin>>n>>m;
    bfs(1,0);    
    return 0;
}