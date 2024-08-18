#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> v[100001],index;

void solve(){
    priority_queue<int,vector<int>,greater<int>> q;
    
    for(int i=1;i<=n;i++) if(index[i]==0) {
        q.push(i);
    }
    while(!q.empty()){
        int now = q.top();
        q.pop();
        cout<<now<<" ";
        for(int j=0;j<v[now].size();j++){
            int tmp = v[now][j];
            if(--index[tmp]==0) q.push(tmp);
        }
    }
    
}

int main()
{
    cin>>n>>m;
    index.assign(n+1,0);
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        
        v[x].push_back(y);
        index[y]++;
    }
    
    solve();
    return 0;
}