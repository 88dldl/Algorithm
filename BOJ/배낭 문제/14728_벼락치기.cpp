#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,t,k[101],s[101];
    int jun[101][10001];
    cin>>n>>t;
    
    for(int i=1;i<=n;i++){
        cin>>k[i]>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(j>=k[i]){
                jun[i][j]=max(jun[i-1][j],jun[i-1][j-k[i]]+s[i]);
            }
            else{
                jun[i][j]=jun[i-1][j];
            }
        }
    }
    cout<<jun[n][t];
    return 0;
}