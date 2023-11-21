#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n,m;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int dp[10001]={1,0};
        int coin[21];
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>coin[j];
        }
        cin>>m;
        for(int j=1;j<=n;j++){
            for(int q=coin[j];q<=m;q++){
                dp[q]+=dp[q-coin[j]];
            }
        }
        
        cout<<dp[m]<<"\n";
    }
    
    return 0;
}