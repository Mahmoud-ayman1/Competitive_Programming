#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll calc(ll n,ll d)
{
    ll ret=0,x=1;
    for(int i=1;x<=n;i++) x*=d,ret+=n/x;
    return ret;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    cout<<min(calc(n,2),calc(n,5));
    return 0;
}
