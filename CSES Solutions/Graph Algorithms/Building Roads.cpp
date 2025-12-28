#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m;vector<int>adj[N];bool vis[N];
void dfs(int node)
{
    vis[node]=1;
    for(auto it:adj[node]) if(!vis[it]) dfs(it);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>ans;
    for(int i=1;i<=n;i++) if(!vis[i]) ans.push_back(i),dfs(i);
    cout<<ans.size()-1<<'\n';
    for(int i=1;i<ans.size();i++) cout<<ans[i-1]<<' '<<ans[i]<<'\n';
    return 0;
}
