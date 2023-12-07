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
array<vector<int>,3>SuffixArray_LCP(string &s)
{
    s+=char(32);
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
    vector<int>lcp(n);
    k=0;
    for(int i=0;i<n-1;i++)
    {
        int pi=c[i],j=p[pi-1];
        while(s[i+k]==s[j+k]) k++;
        lcp[pi]=k;
        k=max(k-1,0);
    }
    return {c,p,lcp};
}
vector<int>seg;int sz,skip=INT_MAX;
int merge(int a,int b)
{
    return min(a,b);
}
void update(int l,int r,int node,int idx,int val)
{
    if(l==r)
    {
        seg[node]=val;
        return;
    }
    int mid=l+r>>1;
    if(mid<idx)
    {
        update(mid+1,r,2*node+2,idx,val);
    }
    else
    {
        update(l,mid,2*node+1,idx,val);
    }
    seg[node]=merge(seg[2*node+1],seg[2*node+2]);
}
int query(int l,int r,int node,int lx,int rx)
{
    if(l>rx||r<lx)return skip;
    if(l>=lx&&r<=rx)return seg[node];
    int mid=l+r>>1;
    int a=query(l,mid,2*node+1,lx,rx);
    int b=query(mid+1,r,2*node+2,lx,rx);
    return merge(a,b);
}
void SegmentTree(int n)
{
    sz=1;
    while(sz<=n)sz<<=1;
    seg=vector<int>(sz<<1,skip);
}
void update(int idx,int val)
{
    update(0,sz-1,0,idx,val);
}
int query(int l,int r)
{
    return query(0,sz-1,0,l,r);
}
string s;vector<int>c,p,lcp;
bool com(pair<int,int>a,pair<int,int>b)
{
    if(a.first==b.first) return a.second<b.second;
    int suf=c[a.first],suf2=c[b.first];
    if(suf>suf2)
    {
        int cp=query(suf2+1,suf),len=a.second-a.first+1,len2=b.second-b.first+1;
        if(len<=cp&&len2<=cp)
        {
            if(len==len2) return a.first<b.first;
            return len<len2;
        }
        else if(len<=cp) return 1;
        else if(len2<=cp) return 0;
        else return 0;
    }
    else
    {
        int cp=query(suf+1,suf2),len=a.second-a.first+1,len2=b.second-b.first+1;
        if(len<=cp&&len2<=cp)
        {
            if(len==len2) return a.first<b.first;
            return len<len2;
        }
        else if(len<=cp) return 1;
        else if(len2<=cp) return 0;
        else return 1;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    array<vector<int>,3>x=SuffixArray_LCP(s);
    c=x[0],p=x[1],lcp=x[2];
    SegmentTree(s.size()+5);
    for(int i=0;i<lcp.size();i++) update(i,lcp[i]);
    int n;cin>>n;
    pair<int,int>v[n];
    for(auto&[a,b]:v) cin>>a>>b,--a,--b;
    sort(v,v+n,com);
    for(auto[a,b]:v) cout<<++a<<' '<<++b<<'\n';
    return 0;
}
