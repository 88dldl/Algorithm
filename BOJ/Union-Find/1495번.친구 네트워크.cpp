#include <iostream>
#include <unordered_map>
using namespace std;

int visit[200001];
int count[200001];

int getParent(int x) {
    if (visit[x] == x) return x;
    return visit[x] = getParent(visit[x]);
}

void uni(int x,int y){
    int num1 = getParent(x);
    int num2 = getParent(y);
    
    if(num1==num2) return;
    
    if(num1<num2) {
        visit[num2] = num1;
        count[num1]+=count[num2];
    }
    else {
        visit[num1] = num2;
        count[num2] += count[num1];
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--){
        int a=0,num;
        unordered_map <string, int> m;
        
        for (int i = 0; i < 200001; i++) {
			visit[i] = i;
			count[i] = 1;
		}
		
        cin>>num; 
        
        for(int i=0;i<num;i++){
            string x,y;
            cin>>x>>y;
            auto tmpn = m.find(x);
            auto tmpm = m.find(y);
            
            if(tmpn == m.end()) {
	            m.insert(make_pair(x, a));
	            a++;
	            tmpn = m.find(x);
            }
            
            if(tmpm == m.end()) {
	            m.insert(make_pair(y, a));
	            a++;
	            tmpm = m.find(y);
            }
    
            uni(tmpn->second, tmpm->second);
            cout<<count[getParent(tmpn->second)]<<"\n";
        }
    }
    return 0;
}