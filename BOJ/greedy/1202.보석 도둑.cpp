#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,k; 

vector<int> m; 
vector<pair<int,int>> v; 
priority_queue<int> pq;
long long sum =0;

void solve(){
    int idx=0;
    
    for(int i=0;i<k;i++){
        while(idx<n && m[i]>=v[idx].first){
            pq.push(v[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }   
    cout<<sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        m.push_back(c);
    }
    
    sort(v.begin(), v.end());
    sort(m.begin(),m.end());
    
    solve();
    return 0;
}