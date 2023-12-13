#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int res,int a=1,int c=2,int b=3)
{
    if(res==0) return;
    solve(res-1,a,b,c);
    cout<<a<<' '<<b<<'\n';
    solve(res-1,c,a,b);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    cout<<(1<<n)-1<<'\n';
    solve(n);
    return 0;
}
