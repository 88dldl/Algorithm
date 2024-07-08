#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int seq[1000001];
vector<int> v;

void solve(){
    for(int i=0;i<n;i++){
        if(v.size()==0 || v[v.size()-1]<seq[i]){
            v.push_back(seq[i]);
        }
        else{
            int pos = lower_bound(v.begin(),v.end(),seq[i])-v.begin();
            v[pos]=seq[i];
        }
    }
    cout<<v.size()<<"\n";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }
    
    solve();
    
    return 0;
}