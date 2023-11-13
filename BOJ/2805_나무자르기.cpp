#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,max=0;
    int start=0,end,mid;
    int tree[1000001];
    
	cin>>n>>m;

    for(int i=0;i<n;i++)
        cin>>tree[i];
    sort(tree,tree+n);
    end=tree[n-1];
    
    while(start<=end){
        long long int sum=0;
        mid=(start+end)/2;
        
        for(int i=0;i<n;i++){
            if(tree[i]>mid) sum+=tree[i]-mid;
        }
        
        if(sum<m){
            end=mid-1;
        }
        else{
            max=mid;
            start=mid+1;
        }
    }
    
    cout<<max;


    return 0;
}