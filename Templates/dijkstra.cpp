const int N=1e5+5;
vector<pair<int,int>>adj[N];vector<int>cost(N,-1);
void dijkstra(int start)
{
    priority_queue<pair<int,int>,deque<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});
    while(pq.size())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int node=p.second,nodecost=p.first;
        if(cost[node]!=-1)
        {
            continue;
        }
        cost[node]=nodecost;
        for(auto [node2,cost2]:adj[node])
        {
            if(cost[node2]==-1)
            {
                pq.push({nodecost+cost2,node2});
            }
        }
    }
}
