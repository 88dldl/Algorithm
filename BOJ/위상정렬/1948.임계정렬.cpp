#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int,int>> v[100001],rev[100001];
vector<int> ind;
int n,m,s,d,cnt=0;
int dp[100001];
bool visit[10001];

void revdfs(){
    queue<int> q;
    q.push(d);
    visit[d]=true;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int i=0;i<rev[now].size();i++){
            int next = rev[now][i].first;
            int w = rev[now][i].second;
            
            if(dp[now]-w == dp[next]){
                cnt++;
                if(!visit[next]){
                    visit[next] = true;
                    q.push(next);
                }
            }
        }
    }
}

void solve(){
    queue<int> q;
    
    for(int i=1;i<=n;i++){
        if(ind[i]==0) q.push(i);
    }
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i].first;
            int w = v[now][i].second;
            dp[next] = max(dp[next],dp[now]+w);

            if(--ind[next]==0) q.push(next);
        }
    }
}

int main()
{
    cin>>n>>m;
    ind.assign(n+1,0);
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        
        v[x].push_back(make_pair(y,w));
        rev[y].push_back(make_pair(x,w));

        ind[y]++;
    }
    cin>>s>>d;
    
    solve();
    revdfs();
    
    cout<<dp[d]<<"\n"<<cnt;
    
    return 0;
}