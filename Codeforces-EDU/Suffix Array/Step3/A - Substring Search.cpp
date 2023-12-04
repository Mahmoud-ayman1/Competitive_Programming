#include<bits/stdc++.h>
using namespace std;
#define ll long long
void countSort(vector<int>&p,vector<int>&c)
{
    int n=p.size();
    vector<int>cnt(n);
    for(auto it:c) cnt[it]++;
    vector<int>p_new(n),pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++) pos[i]=pos[i-1]+cnt[i-1];
    for(auto it:p)
    {
        int i=c[it];
        p_new[pos[i]]=it;
        pos[i]++;
    }
    p=p_new;
}
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
        for(int i=0;i<n;i++) p[i]=(p[i]-(1<<k)+n)%n;
        countSort(p,c);
        vector<int>c_new(n);
        c_new[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            pair<int,int>last={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pair<int,int>cur={c[p[i]],c[(p[i]+(1<<k))%n]};
            if(cur==last) c_new[p[i]]=c_new[p[i-1]];
            else c_new[p[i]]=c_new[p[i-1]]+1;
        }
        c=c_new;
        k++;
    }
    return p;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    vector<int>suf=SuffixArray(s);
    int q;cin>>q;while(q--)
    {
        string x;cin>>x;
        int l=0,r=suf.size()-1,n=s.size(),sz=x.size();string ans="No\n";
        while(l<=r)
        {
            int mid=l+r>>1;
            string w=s.substr(suf[mid],min(n-suf[mid],sz));
            if(w<x)
            {
                l=mid+1;
            }
            else if(w>x)
            {
                r=mid-1;
            }
            else
            {
                ans="Yes\n";
                break;
            }
        }
        cout<<ans;
    }
    return 0;
}
