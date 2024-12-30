#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[501];
bool visit[501];

void solve(){
    int count = 0;
    queue<pair<int,int>> q;
    
    q.push({1,0});
    visit[1]=true;

    while (!q.empty()) {
        int now = q.front().first;
        int depth=q.front().second;
        
        q.pop();
        
        if(depth==2){
            continue;
        }
        
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i];
            
            if (visit[next]) {
                continue;
            }
            count++;
            visit[next]=true;
            q.push({next,depth+1});
        }
    }
    cout<<count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve();
    return 0;
}