#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<ll,int>>adj[n];
    while(m--)
    {
        int a,b,c;cin>>a>>b>>c;
        adj[--a].push_back({--b,c});
     }
    priority_queue<tuple<ll,int,bool>,vector<tuple<ll,int,bool>>,greater<tuple<ll,int,bool>>>pq;
    pq.push({0,0,0});
    ll dis[n][2];
    memset(dis,-1,sizeof dis);
    while(pq.size())
    {
        auto[cost,node,cop]=pq.top();
        pq.pop();
        if(~dis[node][cop]) continue;
        dis[node][cop]=cost;
        for(auto[a,b]:adj[node])
        {
            pq.push({cost+b,a,cop});
            if(!cop)
            {
                pq.push({cost+b/2,a,1});
            }
        }
    }
    cout<<dis[n-1][1];
    return 0;
}
