#include <iostream>
#include <map>
using namespace std;

#define mod 1000000007

long long n;
map<long long,long long> m;

long long fib(long long n){
    if(m[n]) return m[n];
    
    long long result;
    if(n%2==0) result = (fib(n/2)*(fib(n/2+1)+fib(n/2-1)))%mod;
    else result=((fib((n+1)/2) * fib((n+1)/2))%mod)+((fib((n-1)/2)*fib((n-1)/2))%mod)%mod;
    return m[n] = result%mod;
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    m[0]=0;
    m[1]=1;
    m[2]=1;
    cin>>n;
    cout<<fib(n);
    return 0;
}