#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=(1<<18)+5,mod=1e9+7;
ll add(ll a,ll b)
{
    return (((a%mod)+(b%mod))+mod)%mod;
}
ll powmod(ll x,ll y)
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
struct SOS{
    vector<int>dp;int MXN,Log;
    SOS(int n,vector<int>&v)
    {
        Log=n;
        MXN=1<<n;
        dp=v;
    }
    void forward1(){	// adding element to all its super set
        for(int bit=0;bit<Log;bit++)for(int i=0;i<MXN;i++)if(i&(1<<bit)){dp[i]=add(dp[i],dp[i^(1<<bit)]);}}
    void backward1(){	//add a[i] to a[j] if j&i = i
        for(int bit=0;bit<Log;bit++)for(int i=MXN;i>=0;i--)if(i&(1<<bit)){dp[i]-=dp[i^(1<<bit)];}}
    void forward2(){// add elements to its subsets
        for(int bit=0;bit<Log;bit++)for(int i=MXN;i>=0;i--)if(i&(1<<bit)){dp[i^(1<<bit)]+=dp[i];}}
    void backward2(){
        for(int bit=0;bit<Log;bit++)for(int i=0;i<MXN;i++)if(i&(1<<bit)){dp[i^(1<<bit)]=add(dp[i^(1<<bit)],-dp[i]);}}
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int>s(N);
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        s[x]++;
    }
    SOS dp(18,s);
    dp.forward2();
    for(int i=0;i<N;i++)
    {
        dp.dp[i]=add(powmod(2,dp.dp[i]),-1);
    }
    dp.backward2();
    for(int i=0;i<=n;i++)
    {
        cout<<dp.dp[i]<<' ';
    }
    return 0;
}
