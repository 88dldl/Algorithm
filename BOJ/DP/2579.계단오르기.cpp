#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int v[301],tmp[301];

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    tmp[0]=v[0];
    tmp[1]=max(v[1]+v[0],v[1]);
    tmp[2]=max(v[2]+v[1],v[2]+v[0]);
    for(int i=3;i<n;i++){
        tmp[i]=max((tmp[i-2]+v[i]),(tmp[i-3]+v[i-1]+v[i]));
    }
    cout<<tmp[n-1];

    return 0;
}