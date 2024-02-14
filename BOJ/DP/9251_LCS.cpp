#include <iostream>
using namespace std;

string one,two;
int visit[1001][1001]={0};

void solve(){
    for(int i=1;i<=two.length();i++){
        for(int j=1;j<=one.length();j++){
            if(one[j-1]==two[i-1]) visit[i][j]=visit[i-1][j-1]+1;
            else visit[i][j]=max(visit[i-1][j],visit[i][j-1]);
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>one>>two;
    
    solve();

    cout<<visit[two.length()][one.length()];

    return 0;
}