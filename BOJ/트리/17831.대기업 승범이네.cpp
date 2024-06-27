#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int n;
vector<ll> v[200001];
ll power[200001],dp[200001][2]={0};

void solve(ll x){ 
    ll sum=0;
    
    for(int i=0;i<v[x].size();i++){
        ll next=v[x][i];
        solve(next);
        dp[x][0] += max(dp[next][1],dp[next][0]);
        sum+=max(dp[next][1],dp[next][0]);
    }
    
    for(int i=0;i<v[x].size();i++){
        ll next=v[x][i];
        dp[x][1] = max(dp[x][1],sum-max(dp[next][0],dp[next][1])+dp[next][0]+power[x]*power[next]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin>>n;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    
    for(int i=1;i<=n;i++){
        cin>>power[i];
    }
    
    solve(1);
    
    cout<<max(dp[1][0],dp[1][1]);
    return 0;
}