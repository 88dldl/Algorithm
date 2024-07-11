#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>>v;
int n;

void solve (){	
    int maxcount= 0;
    int start = -1000000001;	
    int dest = -1000000001;	

    for (int i = 0; i < n; i++){
        int s = v[i].first;
        int d = v[i].second;
        
        if (s <= dest) dest = max(dest,d);
        else
        {
          maxcount += dest - start;
          start = s;
          dest = d;
        }
    }
    maxcount += dest - start;

    cout << maxcount;
}

int main (){
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin>>n;
    
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort (v.begin(), v.end());
    
    solve();
    return 0;
}