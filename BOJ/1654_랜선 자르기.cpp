#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k,n;
    unsigned int sum,mid,end,max,start=1;
    unsigned int tie[10001];
    cin>>k>>n;
    
    for(int i=0;i<k;i++){
        cin>>tie[i];
    }
    sort(tie,tie+k);
    end=tie[k-1];
    
    while(start<=end){
        sum=0;
        mid=(start+end)/2;
        for(int i=0;i<k;i++){
           sum+=tie[i]/mid; 
        }
        if(sum>=n){
            max=mid;
            start=mid+1;
        }
        else end=mid-1;
    }

    cout<<max;
    return 0;
}