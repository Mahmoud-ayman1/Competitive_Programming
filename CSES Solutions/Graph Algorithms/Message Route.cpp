#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    vector<int>adj[n+1];
    while(m--)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int par[n+1]={};
    queue<int>q;
    q.push(1);
    par[1]=-1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(!par[it])
            {
                par[it]=node;
                q.push(it);
            }
        }
    }
    if(!par[n])
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        deque<int>ans;
        while(n!=-1)
        {
            ans.push_front(n);
            n=par[n];
        }
        cout<<ans.size()<<'\n';
        for(auto it:ans)
        {
            cout<<it<<' ';
        }
 
    }
    return 0;
}
