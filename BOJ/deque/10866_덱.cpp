#include <iostream>
#include <deque>
using namespace std;

int n,num;
string input;
deque <int> dq;

void deq(){
    if(input=="push_back"){
        cin>>num;
        dq.push_back(num);
    }
    else if(input=="push_front"){
        cin>>num;
        dq.push_front(num);
    }
    else if(input=="pop_front"){
        if(dq.size()==0) cout<<-1<<"\n";
        else{
            int tmp;
            tmp=dq.front();
            dq.pop_front();
            cout<<tmp<<"\n";
        }
    }
    else if(input=="pop_back"){
        if(dq.size()==0) cout<<-1<<"\n";
        else{
            int tmp;
            tmp=dq.back();
            dq.pop_back();
            cout<<tmp<<"\n";
        }
    }
    else if(input=="size"){
        cout<<dq.size()<<"\n";
    }
    else if(input=="empty"){
        if(dq.size()==0) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    else if(input=="front"){
        if(dq.size()==0) cout<<-1<<"\n";
        else cout<<dq.front()<<"\n";
    }
    else if(input=="back"){
        if(dq.size()==0) cout<<-1<<"\n";
        else cout<<dq.back()<<"\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>input;
        deq();
    }
    
    return 0;
}