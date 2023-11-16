#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int w[101],v[101],sum[101][100001];


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(w[i]<=j){
               sum[i][j]=max(sum[i-1][j],sum[i-1][j-w[i]]+v[i]); 
            }
            else sum[i][j]=sum[i-1][j];
        }
    }
    cout<<sum[n][k];
    return 0;
}