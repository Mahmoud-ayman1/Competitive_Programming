#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool Knowbit(ll n,int i)
{
    return (n>>i)&1;
}
ll Setbit(ll n,int i)
{
    return n|(1<<i);
}
ll Resetbit(ll n,int i)
{
    return n&(~(1<<i));
}
ll flip(ll n,int i)
{
    return n^(1<<i);
}
bool isPowerOfTwo(int n)
{
    if(n==0)return 0;
    return !(n&(n-1));
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    int ans=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int even=0,odd=0;
        for(int i=0;i<n;i++)
        {
            if(Knowbit(mask,i)==1)
            {
                if(s[i]&1) odd++;
                else even++;
            }
        }
        if(even>odd) ans++;
    }
    cout<<ans;
    return 0;
}
