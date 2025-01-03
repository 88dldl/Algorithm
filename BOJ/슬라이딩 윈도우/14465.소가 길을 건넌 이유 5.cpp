#include <iostream>
#include <vector>
using namespace std;

int n,k,b;
int blinker[100001];

void solve(){
	for (int i=2; i<=n; i++)
		blinker[i]+=blinker[i-1];

	int m = 0;
	for (int i=k; i<=n; i++)
		m=max(m,blinker[i]-blinker[i-k]);

	cout<<k-m;
}

int main()
{
    cin>>n>>k>>b;
    
    fill(blinker,blinker+n+1,1);
    
    for(int i=0;i<b;i++){
        int x;
        cin>>x;
        blinker[x]=0;
    }
    
    solve();
    
    return 0;
}