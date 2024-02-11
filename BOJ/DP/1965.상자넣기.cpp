#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n,maxtmp;
int visit[1001]={0};

void solve(){
    visit[0]=1;
    for(int j=1;j<n;j++){
        maxtmp=0;
        for(int i=j-1;i>=0;i--){
            if(v[i]<v[j]) maxtmp=max(maxtmp,visit[i]);
        }
        visit[j]=maxtmp+1;
    }
}

int main()
{
    cin>>n;
    
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    solve();
    
    int fin = visit[0];
    for(int i=1;i<n;i++){
        fin=max(fin,visit[i]);
    }
    cout<<fin;
    
    return 0;
}