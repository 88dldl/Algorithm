#include <iostream>

using namespace std;
int n,m;
int arr[9];
int visit[9]={0};

void bfs(int x,int num){
    if(num==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<"\n";
        return;
    }
    
    for(int i=x;i<=n;i++){ 
        visit[i]++;
        arr[num]=i;
        if(visit[i]<m){
            bfs(i,num+1);
        }
        else{
            bfs(i+1,num+1);
        }
        visit[i]--;

    }
}

int main()
{
    cin>>n>>m;
    bfs(1,0);    
    return 0;
}