#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;   
vector<pair<int,int>> v[1001];
vector<bool> visit(1001,false);
int node1,node2;

void solve(int x,int sum){
    if(x==node2) {
        cout<<sum<<"\n";
        return;
    }
    for(int i=0;i<v[x].size();i++){
        if(!visit[v[x][i].first]){
            visit[v[x][i].first]=true;
            solve(v[x][i].first,sum+v[x][i].second);
            visit[v[x][i].first]=false;
        }
    }
    return;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }   
    for(int i=0;i<m;i++){
        cin>>node1>>node2;
        visit = vector<bool>(1001,false);
        visit[node1]=true;
        solve(node1,0);
    }
    return 0;
}