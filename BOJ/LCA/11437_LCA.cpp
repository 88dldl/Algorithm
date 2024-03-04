#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> v[100001];
int parent[100001],level[100001];

void LCA(int x, int y){
    if(level[x]<level[y]) swap(x,y);
    
    while(level[x]!=level[y]){
        x=parent[x];
    }
    
    while(x!=y){
        x=parent[x];
        y=parent[y];
    }
    cout<<x<<"\n";
    return;
}
void setting(int x,int y){
    parent[x]=y;
    level[x]=level[y]+1;
    
    for(int i=0;i<v[x].size();i++){
        int child = v[x][i];
        if(child==y) continue;
        setting(child,x);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    setting(1,0);
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        LCA(x,y);
    }
    return 0;
}