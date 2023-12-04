#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>SuffixArray(string &s)
{
    s+='$';
    int n=s.size();
    vector<pair<char,int>>suf(n);
    for(int i=0;i<n;i++) suf[i]={s[i],i};
    sort(suf.begin(),suf.end());
    vector<int>p(n),c(n);
    for(int i=0;i<n;i++) p[i]=suf[i].second;
    c[p[0]]=0;
    for(int i=1;i<n;i++)
    {
        if(suf[i].first==suf[i-1].first) c[p[i]]=c[p[i-1]];
        else c[p[i]]=c[p[i-1]]+1;
    }
    int k=0;
    while((1<<k)<n)
    {
        vector<pair<pair<int,int>,int>>su(n);
        for(int i=0;i<n;i++) su[i]={{c[i],c[(i+(1<<k))%n]},i};
        sort(su.begin(),su.end());
        for(int i=0;i<n;i++) p[i]=su[i].second;
        c[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(su[i].first==su[i-1].first) c[p[i]]=c[p[i-1]];
            else c[p[i]]=c[p[i-1]]+1;
        }
        k++;
    }
    return p;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    vector<int>suf=SuffixArray(s);
    for(auto it:suf) cout<<it<<' ';
    return 0;
}
