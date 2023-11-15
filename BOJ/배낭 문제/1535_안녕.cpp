#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    int loss[21],get[21],dp[21][101];
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>loss[i];
    }
    for(int i=1;i<=n;i++){
        cin>>get[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<101;j++){
            if(loss[i]>=j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-loss[i]]+get[i]);
            }
        }
    }
    cout<<dp[n][100];
    
    return 0;
}
