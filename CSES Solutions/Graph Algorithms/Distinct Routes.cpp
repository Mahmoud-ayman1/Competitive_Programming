#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=501,OO=1e18;
int n,m,cap[N][N];vector<int>par,adj[N];bool ed[N][N];vector<int>path;
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
bool getPath(int node,int goal)
{
    if(node==goal) return 1;
    for(auto it:adj[node])
    {
        if(cap[node][it]==0&&ed[node][it]&&getPath(it,goal))
        {
            cap[node][it]=-1;
            path.push_back(it);
            return 1;
        }
    }
    return 0;
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
        ed[a][b]=1;
        cap[a][b]++;
    }
    int flow=maxFlow(1,n);
    cout<<flow<<'\n';
    while(flow--)
    {
        path.clear();
        getPath(1,n);
        path.push_back(1);
        cout<<path.size()<<'\n';
        for(int i=path.size()-1;i>=0;i--)
        {
            cout<<path[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
