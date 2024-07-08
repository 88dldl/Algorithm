#include <iostream>
#include <vector>
using namespace std;

int n;
int seq[1001],dp[1001];
vector<int> v[1001],ans;

void solve(){
    for(int i=1;i<=n;i++){
        dp[i]=1;
        v[i].push_back(seq[i]);
        
        for(int j=1;j<i;j++){
            if(seq[i]>seq[j]){
                if(dp[i]<dp[j]+1){
                    v[i].clear();
                    v[i]=v[j];
                    v[i].push_back(seq[i]);
                    dp[i]=dp[j]+1;
                }
            }
        }

        if(v[i].size()>ans.size()){
            ans=v[i];
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>seq[i];
    }
    
    solve();
    
    return 0;
}