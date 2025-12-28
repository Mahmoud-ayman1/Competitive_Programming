#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,m,ans[N];vector<int>adj[N];bool can=1;
void dfs(int node,int par)
{
    for(auto it:adj[node])
    {
        if(it==par)
        {
            continue;
        }
        if(ans[it])
        {
            if(ans[it]!=3-ans[node])
            {
                can=0;
                return;
            }
        }
        else
        {
            ans[it]=3-ans[node];
            dfs(it,node);
        }
    }
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
    for(int i=1;i<=n;i++)
    {
        if(!ans[i])
        {
            ans[i]=1;
            dfs(i,i);
        }
    }
    if(can)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<' ';
        }
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
