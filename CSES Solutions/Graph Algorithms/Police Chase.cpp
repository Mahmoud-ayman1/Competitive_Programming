#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=501,OO=1e18;
int n,m,cap[N][N];vector<int>par,adj[N];bool vis[N];
int getFlow(int src,int sink)
{
    fill(par.begin(),par.end(),-1);
    par[src]=-2;
    queue<pair<int,int>>q;
    q.push({src,OO});
    while(!q.empty())
    {
        int node=q.front().first;
        int flow=q.front().second;
        q.pop();
        for(auto it:adj[node])
        {
            if(par[it]==-1&&cap[node][it])
            {
                par[it]=node;
                int newFlow=min(flow,cap[node][it]);
                if(it==sink) return newFlow;
                q.push({it,newFlow});
            }
        }
    }
    return 0;
}
int maxFlow(int src,int sink)
{
    int flow=0;
    par=vector<int>(n+1);
    int nxt;
    while(nxt=getFlow(src,sink))
    {
        flow+=nxt;
        int cur=sink;
        while(cur!=src)
        {
            int u=par[cur],v=cur;
            cap[u][v]-=nxt;
            cap[v][u]+=nxt;
            cur=u;
        }
    }
    return flow;
}
void dfs(int node)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it]&&cap[node][it])
        {
            dfs(it);
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vector<pair<int,int>>ed;
    while(m--)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ed.push_back({a,b});
        cap[a][b]++;
        cap[b][a]++;
    }
    cout<<maxFlow(1,n)<<'\n';
    dfs(1);
    for(auto[a,b]:ed)
    {
        if((vis[a]&&!vis[b]) or (!vis[a]&&vis[b]))
        {
            cout<<a<<' '<<b<<'\n';
        }
    }
    return 0;
}
