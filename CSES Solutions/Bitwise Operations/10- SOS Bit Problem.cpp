#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SOS{
    vector<int>dp;int MXN,Log;
    SOS(int n,vector<int>&v)
    {
        Log=n;
        MXN=1<<n;
        dp=v;
    }
    void forward1(){	// adding element to all its super set
        for(int bit=0;bit<Log;bit++)for(int i=0;i<MXN;i++)if(i&(1<<bit)){dp[i]+=dp[i^(1<<bit)];}}
    void backward1(){	//add a[i] to a[j] if j&i = i
        for(int bit=0;bit<Log;bit++)for(int i=MXN;i>=0;i--)if(i&(1<<bit)){dp[i]-=dp[i^(1<<bit)];}}
    void forward2(){// add elements to its subsets
        for(int bit=0;bit<Log;bit++)for(int i=MXN;i>=0;i--)if(i&(1<<bit)){dp[i^(1<<bit)]+=dp[i];}}
    void backward2(){
        for(int bit=0;bit<Log;bit++)for(int i=0;i<MXN;i++)if(i&(1<<bit)){dp[i^(1<<bit)]-=dp[i];}}
};
const int N=(1<<23);
int n,s[N];vector<int>f(N);
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        f[s[i]]++;
    }
    SOS a(23,f),b(23,f);
    a.forward1();
    b.forward2();
    for(int i=0;i<n;i++)
    {
        cout<<a.dp[s[i]]<<' '<<b.dp[s[i]]<<' '<<n-a.dp[(N-1)^s[i]]<<'\n';
    }
    return 0;
}
