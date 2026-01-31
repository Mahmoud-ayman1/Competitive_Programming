#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const long double pi=3.14159265358979323846;
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;cin>>n>>m;
    ld tot=0;
    while(m--)
    {
        ld r;cin>>r;
        tot+=pi*r*r;
    }
    cout<<fixed<<setprecision(6)<<tot/((ld)n*n);
    return 0;
}
