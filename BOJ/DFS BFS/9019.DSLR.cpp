#include <iostream>
#include <queue>

using namespace std;

int t,a,b;

int remparent[10002];
char parent[10002];

void bfs(){
    bool visit[10000]={false};
    queue<int> q;
    parent[a]=-1;
    visit[a]=true;
    q.push(a);
    
    while(!q.empty()){
        int first = q.front();
        q.pop();
        int d,s,l,r;
        
        //D
        d = (first*2)%10000;
        if(!visit[d]){
            visit[d]=true;
            q.push(d);
            remparent[d]=first;
            parent[d]='D';
            if(b==d) return;            
        }

        //S
        if(first==0) s = 9999;
        else s = first-1;
        if(!visit[s]){
            visit[s]=true;
            q.push(s);
            remparent[s]=first;
            parent[s]='S';
            if(b==s) return;
        }
        
        //l 
        l = ((first/1000) + (first%1000)*10)%10000; 
        if(!visit[l]){
            visit[l]=true;
            q.push(l);
            remparent[l]=first;
            parent[l]='L';
            if(b==l) return;
        }
        
        //R
        r = ((first/10) + (first%10)*1000)%10000;
        if(!visit[r]){
            visit[r]=true;  
            q.push(r);
            remparent[r]=first;
            parent[r]='R';
            if(b==r) return;
        }   
    }
}

void printPath(int b) {
    if (parent[b] == -1) return;
    printPath(remparent[b]);
    cout<<parent[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    
    cin >> t;
    
    while (t--) {
        cin >> a >> b;
        bfs();
        if (parent[b] != -1) {
            printPath(b);
            cout<<"\n";
        }
    }
    
    return 0;
}