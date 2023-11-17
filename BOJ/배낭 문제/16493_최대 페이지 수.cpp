#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n,m;
    int sum[21][201];
    int day[201],page[21];
    cin>>n>>m;
    
    for(int i=1;i<=m;i++){
        cin>>day[i]>>page[i];
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j>=day[i]){
                sum[i][j]=max(sum[i-1][j],sum[i-1][j-day[i]]+page[i]);
            }
            else{
                sum[i][j]=sum[i-1][j];
            }
        }
    }
    cout<<sum[m][n];
    return 0;
}