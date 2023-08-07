#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mulmod(ll a, ll b, ll m)
{
    ll res = 0;
    while(b > 0)
    {
        if(b & 1)  res = ((m-res) > a) ? res+a : res+a-m;
        b >>= 1;
        if (b) a = ((m-a) > a) ? a+a : a+a-m;
    }
    return res;
}

ll power(ll a, ll b, ll m)
{
    if(b == 0) return 1;
    if(b & 1) return mulmod(a, power(a, b - 1, m), m);
    ll tmp = power(a, b / 2, m);
    return mulmod(tmp, tmp, m);
}

bool prime(ll n)
{
    if(n<=1)return 0;
    for(int i=0;i<10;i++)
    {
        ll tmp = (rand() % (n - 1)) + 1;
        if(power(tmp, n - 1, n) != 1)
            return false;
    }
    return true;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    if(prime(n))
    {
        cout<<"Prime";
    }
    else
    {
        cout<<"Not Prime";
    }
    return 0;
}
