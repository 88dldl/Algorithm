#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int start=0,end,mid,max=0,count,install;
    int n,c;
    vector<int> x;
    cin>>n>>c;
    
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        x.push_back(tmp);
    }
    sort(x.begin(),x.end());
    end=x.back();
    
    while(start<=end){
        mid=start+(end-start)/2;
        install=x[0];
        count=1;
        for(int i=0;i<n;i++){
            if(x[i]-install>=mid){
                count++;
                install=x[i];
            }
        }
        if(count>=c){
            start=mid+1;
            if(max<mid) max=mid;
        }
        else end=mid-1;
    }
    cout<<max;
    return 0;
}