#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5+5,Log=23;
int n,q,anc[N][Log],sz[N],level[N],parent[N],best[N];vector<int>adj[N];bool vis[N];
void BuildAncestors(int node,int par)
{
    level[node]=level[par]+1;
    anc[node][0]=par;
    for(int o=1;o<Log;o++)
    {
        int p=anc[node][o-1];
        anc[node][o]=anc[p][o-1];
    }
    for(auto it:adj[node])
    {
        if(it==par) continue;
        BuildAncestors(it,node);
    }
}
int KthAncestor(int node,int k)
{
    for(int o=Log-1;o>=0;o--)
    {
        if(k&(1<<o))
        {
            node=anc[node][o];
        }
    }
    return node;
}
int LCA(int u,int v)
{
    if(level[u]<level[v])swap(u,v);
    u=KthAncestor(u,level[u]-level[v]);
    if(u==v) return u;
    for(int i=Log-1;i>=0;i--)
    {
        if(anc[u][i]!=anc[v][i])
        {
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    return anc[u][0];
}
void dfs(int node,int par)
{
    if(vis[node])return;
    sz[node]=1;
    for(auto it:adj[node])
    {
        if(it!=par&&!vis[it])
        {
            dfs(it,node);
            sz[node]+=sz[it];
        }
    }
}
int findCentriod(int node,int par,int size)
{
    for(auto it:adj[node])
    {
        if(it!=par&&!vis[it]&&sz[it]>size/2) return findCentriod(it,node,size);
    }
    return node;
}
void initCentroid(int node,int par)
{
    dfs(node,0);
    node=findCentriod(node,0,sz[node]);
    vis[node]=1;
    parent[node]=par;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            initCentroid(it,node);
        }
    }
}
int dis(int a,int b)
{
    int lc=LCA(a,b);
    return level[a]+level[b]-2*level[lc];
}
void update(int node)
{
    best[node]=0;
    int u=node;
    while(parent[u]!=0)
    {
        u=parent[u];
        best[u]=min(best[u],dis(u,node));
    }
}
int query(int node)
{
    int ret=best[node];
    int u=node;
    while(parent[u]!=0)
    {
        u=parent[u];
        ret=min(ret,best[u]+dis(u,node));
    }
    return ret;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(auto&it:best) it=2e5;
    BuildAncestors(1,0);
    initCentroid(1,0);
    update(1);
    while(q--)
    {
        int op,node;cin>>op>>node;
        if(op==1)
        {
            update(node);
        }
        else
        {
            cout<<query(node)<<'\n';
        }
    }
    return 0;
}
