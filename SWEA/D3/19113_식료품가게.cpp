#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin>>tc;

    for(int i=1;i<=tc;i++){
        int n,min=0;
        long tmp;
        vector<long> v,discount;
        cin>>n;
        for(int j=0;j<n*2;j++){
            cin>>tmp;
            v.push_back(tmp);
        }
        cout<<"#"<<i<<" ";
        
        for(int j=0;j<n*2-1;j++){
            if(v[j]==-1) continue;
            int index = find(v.begin()+min+1,v.end(),v[j]*4/3)-v.begin();
            if(v[index]!=-1){
                discount.push_back(v[j]);
                v[index]=-1;
                min=index;
            }
        }
        for(int j=0;j<discount.size();j++){
            cout<<discount[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}