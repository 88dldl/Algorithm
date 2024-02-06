#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long cardPay[1001];

void solve(){
    for(int i=2;i<=n;i++){ 
        for(int j=1;j<i;j++){ 
           cardPay[i]=max(cardPay[i-j]+cardPay[j],cardPay[i]);
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cardPay[i];
    }
    solve();
    cout<<cardPay[n];
    return 0;
}