#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,l;
    int count=0;
    vector<int> point;
    cin>>n>>l;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        point.push_back(tmp);
    }
    
    sort(point.begin(),point.end()); 

    for(int i=0;i<point.size();i++){
        int index= upper_bound(point.begin()+i,point.end(),point[i]+l-1)-point.begin();
        i=index-1;
        count++;
    }
    cout<<count;
    
    return 0;
}