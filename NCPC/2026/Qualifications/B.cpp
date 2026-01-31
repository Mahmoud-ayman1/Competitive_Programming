#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
string s,f;ll a,b,dp[20][2][2][2],d,m;int n;int li[20],st[20];string ans="";
ll solve(int i=0,bool start=0,bool end=0,bool led=0)
{
    if(i==n) return 0;
    ll &ret=dp[i][start][end][led];
    if(~ret) return ret;
    int limit=9,go=0;
    if(!end) limit=s[i]-'0';
    if(!start) go=f[i]-'0';
    ret=100;
    for(int o=go;o<=limit;o++)
    {
        ret=min(ret,solve(i+1,start|((f[i]-'0')!=o),end|(o<limit),led|(o!=0))+(led&&o==0));
    }
    return ret;
}
void print(int i=0,bool start=0,bool end=0,bool led=0)
{
    if(i==n) return;
    ll &ret=dp[i][start][end][led];
    int limit=9,go=0;
    if(!end) limit=s[i]-'0';
    if(!start) go=f[i]-'0';
    for(int o=go;o<=limit;o++)
    {
        if(ret==solve(i+1,start|((f[i]-'0')!=o),end|(o<limit),led|(o!=0))+(led&&o==0))
        {
            ans.push_back(char(o+'0'));
            print(i+1,start|((f[i]-'0')!=o),end|(o<limit),led|(o!=0));
            return;
        }
    }
    return;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        ans="";
        cin>>a>>b;
        s=to_string(b);
        f=to_string(a);
        memset(dp,-1,sizeof dp);
        while(f.size()<s.size()) f='0'+f;
        while(s.size()<f.size()) s='0'+s;
        n=s.size();
        solve();
        print();
        ll v=stoll(ans);
        cout<<v-a<<'\n';
    }
    return 0;
}
