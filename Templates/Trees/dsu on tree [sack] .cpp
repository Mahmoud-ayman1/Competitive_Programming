#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
int n,c[N],sz[N],ans[N];vector<int>adj[N],subTree[N];map<int,int>m;
void dfs(int node,int par)
{
    sz[node]=1;
    for(auto it:adj[node])
    {
        if(it!=par)
        {
            dfs(it,node);
            sz[node]+=sz[it];
        }
    }
}
void sack(int node,int par,bool keep)
{
    // find big child
    int mx=-1,bigCh=-1;
    for(auto it:adj[node])
    {
        if(it!=par&&mx<sz[it])
        {
            mx=sz[it];
            bigCh=it;
        }
    }
    // go deep into small children
    for(auto it:adj[node])
    {
        if(it!=par&&it!=bigCh)
        {
            sack(it,node,0);
        }
    }
    // go deep into big child
    if(~bigCh)
    {
        sack(bigCh,node,1);
        swap(subTree[node],subTree[bigCh]);
    }
    // add information of node
    subTree[node].push_back(node);
    m[c[node]]++;
    for(auto it:adj[node])
    {
        if(it!=par&&it!=bigCh)
        {
            for(auto u:subTree[it])
            {
                m[c[u]]++;
                subTree[node].push_back(u);
            }
        }
    }
    ans[node]=m.size();
    // small to large
    if(keep==0)
    {
        for(auto it:subTree[node])
        {
            m[c[it]]--;
            if(m[c[it]]==0) m.erase(m.find(c[it]));
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    sack(1,1,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    return 0;
}
