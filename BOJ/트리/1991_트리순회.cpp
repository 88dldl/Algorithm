#include <iostream>
#include <vector>
using namespace std;

int n;
vector<char> v[27];

void pre(int x){ //root -> left -> right
    if(x==-1) return;
    cout<<(char)(x+'A');
    pre(v[x][0]);
    pre(v[x][1]);
}

void in(int x){ //left -> root -> right
    if(x==-1) return;
    in(v[x][0]);
    cout<<(char)(x+'A');
    in(v[x][1]);
}

void post(int x){ //left ->right->root
    if(x==-1) return;
    post(v[x][0]);
    post(v[x][1]);
    cout<<(char)(x+'A');
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    
    for(int i=0;i<n;i++){
        char x,y,z;
        cin>>x>>y>>z;
        if(y=='.') v[x-'A'].push_back(-1);
        else v[x-'A'].push_back(y-'A');
        if(z=='.') v[x-'A'].push_back(-1);
        else v[x-'A'].push_back(z-'A');
    }
    
    pre(0);
    cout<<"\n";
    in(0);
    cout<<"\n";
    post(0);
    return 0;
}