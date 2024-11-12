#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
int n,c[N],sz[N],parent[N],p[N],lvl[N],ans[N];set<int>st[N];vector<int>adj[N];
void dfs(int node,int par,int level)
{
    lvl[node]=level;
    p[node]=par;
    for(auto it:adj[node])
    {
        if(it!=par)
        {
            dfs(it,node,level+1);
        }
    }
}
int find(int node)
{
    if(parent[node]==node) return node;
    return parent[node]=find(parent[node]);
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        sz[i]=1;
        st[i].insert(c[i]);
    }
}
void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(sz[b]>sz[a]) swap(a,b);
    sz[a]+=sz[b];
    for(auto it:st[b]) st[a].insert(it);
    parent[b]=a;
    st[b].clear();
}
bool com(int a,int b)
{
    return lvl[a]>lvl[b];
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
    dfs(1,0,0);
    init();
    int node[n];
    iota(node,node+n,1);
    sort(node,node+n,com);
    for(int i=0;i<n;i++)
    {
        ans[node[i]]=st[find(node[i])].size();
        merge(node[i],p[node[i]]);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    return 0;
}
