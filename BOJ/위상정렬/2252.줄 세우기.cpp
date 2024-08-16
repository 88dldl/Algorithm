#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v,result;
vector<int> map[100001];
int n,m;

void solve(){
    queue<int> q;
    
    for(int i=1;i<=n;i++){
        if(v[i]==0) q.push(i);
    }
    
    for(int i=0;i<n;i++){
        if(q.empty()) return;
        int now = q.front();
        q.pop();
        
        result[i]=now;
        
        for(int j=0;j<map[now].size();j++){
            int next = map[now][j];
            if(--v[next]==0) q.push(next);
        }
    }
}

int main()
{
    cin>>n>>m;
    v.assign(n + 1, 0);
    result.assign(n + 1, 0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        v[b]++;
    }
    solve();
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}