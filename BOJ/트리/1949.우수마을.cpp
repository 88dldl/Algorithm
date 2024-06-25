#include <iostream>
#include <vector>

using namespace std;

int n;
int people[10001];
vector<int> v[10001];
bool visit[10001];
int dp[10001][2];

void dfs(int x){
    visit[x]=true;
    
    dp[x][0]=0;
    dp[x][1]=people[x];
    
    
    for(int i=0;i<v[x].size();i++){
        int next = v[x][i];
        if(visit[next]) continue;
        dfs(next);
        dp[x][0] += max(dp[next][0],dp[next][1]);
        dp[x][1] += dp[next][0];
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>people[i];
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(1);
    cout<<max(dp[1][0],dp[1][1]);
    return 0;
}