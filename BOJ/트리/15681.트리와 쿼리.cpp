#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[100001];
int dp[100001];
bool visit[100001];

int solve(int x){ 
    if(visit[x]) return dp[x];
    visit[x]=true;
    
    for(int i=0;i<v[x].size();i++){
        int next = v[x][i];
        if(visit[next]) continue;
        dp[x]+=solve(next);
    }
    return dp[x];
}

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,r,q;
    cin>>n>>r>>q;
    
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        dp[i]=1;
    }
    memset(visit,false,sizeof(visit));
    solve(r);
    
    for(int i=0;i<q;i++){
        int tmp;
        cin>>tmp;
        cout<< dp[tmp]<<"\n";
    }

    return 0;
}