#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int n,sumof=0,point=0;
vector<pair<int,int>> v[100001];
int visit[100001]={false};

void dfs(int x,int len){
    if(visit[x]) return;
    
    visit[x]=true;
    
    if(sumof<len){//최대값 갱신
        sumof=len;
        point = x;
    }
    for(int i=0;i<v[x].size();i++){
        dfs(v[x][i].first,len+v[x][i].second);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        int x,z,y;
        cin>>x>>y;
        if(y==-1) continue;
        while(y!=-1){
            cin>>z;
            v[x].push_back({y,z});
            v[y].push_back({x,z});
            cin>>y;
        }
    }
    dfs(1,0);
    
    sumof=0;
    memset(visit,false,sizeof(visit));
    
    dfs(point,0);
    cout<<sumof;
    return 0;
}