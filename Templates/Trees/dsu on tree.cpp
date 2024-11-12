#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,q,sz[N],lvl[N],cnt[N],mask[N];vector<pair<int,int>>qu[N];vector<int>adj[N];string s,ans[N];bool big[N];
void dfs0(int node,int l)
{
    lvl[node]=l;
    sz[node]=1;
    for(auto it:adj[node])
    {
        dfs0(it,l+1);
        sz[node]+=sz[it];
    }
}
void add(int node,int p,int x)
{
    mask[lvl[node]]^=(1<<(s[node]-'a'));
    for(auto u:adj[node])
    {
        if(u!=p&&!big[u])
        {
            add(u,node,x);
        }
    }
}
void dfs(int node,int par,bool keep)
{
    int mx=-1,bigChild=-1;
    for(auto u:adj[node])
    {
        if(u!=par&&sz[u]>mx)
        {
            mx=sz[u],bigChild=u;
        }
    }
    for(auto u:adj[node])
    {
        if(u!=par&&u!=bigChild)
        {
            dfs(u,node,0);
        }
    }
    if(bigChild!=-1)
    {
        dfs(bigChild,node,1);
        big[bigChild]=1;
    }
    add(node,par,1);
    // here answer queries
    for(auto [h,i]:qu[node])
    {
        if(__builtin_popcount(mask[h])<=1)
        {
            ans[i]="Yes\n";
        }
        else
        {
            ans[i]="No\n";
        }
    }
    if(bigChild!=-1)
    {
        big[bigChild]=0;
    }
    if(keep==0)
    {
        add(node,par,-1);
    }
}
