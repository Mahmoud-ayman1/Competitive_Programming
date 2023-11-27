#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    cout<<n<<' ';
    while(n!=1)
    {
        if(n&1) n=n*3+1;
        else n/=2;
        cout<<n<<' ';
    }
    return 0;
}
