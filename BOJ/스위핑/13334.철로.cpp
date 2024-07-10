#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> q;
vector<pair<int,int>> v;
int n,d,maxcount=0;

void solve(){ 
    for(int i=0;i<v.size();i++){
        int start = v[i].first;
        int dest = v[i].second;
        
        if(dest-start>d) continue;
        q.push(-start);
        
        while(!q.empty()){
            if(-q.top()<dest-d) q.pop();
            else{
                maxcount = max(maxcount, (int)q.size());
                break;
            }
        }
    }
    cout<<maxcount;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x < y) v.push_back(make_pair(x,y));
        else v.push_back(make_pair(y,x));
    }
    cin >> d;
    
    sort(v.begin(), v.end(), compare);
    
    solve();
    
    return 0;
}
