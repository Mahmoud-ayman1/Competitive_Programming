#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct XorBasis{
    int d,sz;vector<ll>basis;
    XorBasis(int n)
    {
        sz=0;
        d=n+1;
        basis=vector<ll>(d);
    }
    void insert(int mask)
    {
        for(int i=d-1;i>=0;i--)
        {
            if((mask>>i)&1)
            {
                if(!basis[i])
                {
                    basis[i]=mask;
                    sz++;
                    return;
                }
                mask^=basis[i];
            }
        }
    }
    bool check(int mask)
    {
        for(int i=d-1;i>=0;i--)
        {
            if((mask>>i)&1)
            {
                if(!basis[i])
                {
                    return 1;
                }
                mask^=basis[i];
            }
        }
        return 0;
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    XorBasis xr(32);
    while(n--)
    {
        int x;cin>>x;
        xr.insert(x);
    }
    cout<<(1<<xr.sz);
    return 0;
}
