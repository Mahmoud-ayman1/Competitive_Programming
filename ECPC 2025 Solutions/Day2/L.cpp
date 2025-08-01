#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update>// set
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
#define ll long long
ll powmod(ll x,ll y,ll mod)
{
    ll res=1;
    x=x%mod;
    if(x==0) return 0;
    while(y>0)
    {
        if(y&1) res=(res*x)%mod;
        y=y>>1;
        x=(x*x)%mod;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        pair<int,int>s[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i].first;
        }
        for(int i=0;i<n;i++)
        {
            cin>>s[i].second;
        }
        sort(s,s+n,greater<pair<int,int>>());
        ordered_multiset ms;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i].first>s[i].second)
            {
                ans+=powmod(2,ms.order_of_key(s[i].first),1e9+7);
                ans%=1000000007;
            }
            ms.insert(s[i].second);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
