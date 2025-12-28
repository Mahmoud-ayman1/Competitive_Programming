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
        adj[--a].push_back({c,--b});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,0});
    vector<ll>dis(n,-1);
    while(pq.size())
    {
        auto[cost,node]=pq.top();
        pq.pop();
        if(~dis[node]) continue;
        dis[node]=cost;
        for(auto[a,b]:adj[node])
        {
            pq.push({cost+a,b});
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<dis[i]<<' ';
    }
    return 0;
}
