#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int index[4000001];

int getParent(int x){
    if(index[x]==x) return x;
    return index[x] = getParent(index[x]);
}

void uni(int x,int y){
    int num1 = getParent(x);
    int num2 = getParent(y);
    
    if(num1>num2) {
        index[num2] = num1;
    }
    else {
        index[num1] = num2;
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n,m,k;
    vector<int> v;

    cin>>n>>m>>k;
    
    for(int i=0;i<m;i++){
        index[i]=i;
    }
    
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(),v.end());
    
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        
        int check = lower_bound(v.begin(), v.end(), tmp+1) - v.begin();
        cout<<v[getParent(check)]<<"\n";
        if (check < m) uni(getParent(check), getParent(check) + 1);
    }
    return 0;
}