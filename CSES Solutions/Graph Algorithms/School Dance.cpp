#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=501;
int n,m,k,mat[N];vector<int>adj[2*N];bool vis[N];
bool can_match(int node)
{
    if(vis[node]) return 0;
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(mat[it]==-1||can_match(mat[it]))
        {
            mat[it]=node;
            return 1;
        }
    }
    return 0;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    while(k--)
    {
        int a,b;cin>>a>>b;
        adj[b].push_back(a);
    }
    memset(mat,-1,sizeof mat);
    for(int i=1;i<=m;i++)
    {
        memset(vis,0,sizeof vis);
        can_match(i);
    }
    map<int,int>ans;
    for(int i=1;i<=n;i++)
    {
        if(~mat[i])
        {
            ans[i]=mat[i];
        }
    }
    cout<<ans.size()<<'\n';
    for(auto [a,b]:ans)
    {
        cout<<a<<' '<<mat[a]<<'\n';
    }
    return 0;
}
