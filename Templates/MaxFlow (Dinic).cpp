struct Dinic{
    struct FlowEdge{
        int v,u;
        ll cap,flow=0;
        FlowEdge(int v,int u,ll cap):v(v),u(u),cap(cap){}
    };
    const ll flow_inf=1e18;
    vector<FlowEdge>edges;vector<vector<int>>adj;vector<int>level,ptr;queue<int>q;
    int n,m=0,s,t;
    Dinic(int n,int start,int goal):n(n),s(start),t(goal)
    {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int v,int u,ll cap)
    {
        edges.emplace_back(v,u,cap);
        edges.emplace_back(u,v,0);
        adj[v].push_back(m);
        adj[u].push_back(m+1);
        m+=2;
    }
    bool bfs()
    {
        while(!q.empty())
        {
            auto v=q.front();
            q.pop();
            for(int id:adj[v])
            {
                if(edges[id].cap==edges[id].flow) continue;
                if (level[edges[id].u] != -1) continue;
                level[edges[id].u]=level[v]+1;
                q.push(edges[id].u);
            }
        }
        return ~level[t];
    }
    ll dfs(int v,ll pushed)
    {
        if(pushed==0) return 0;
        if(v==t) return pushed;
        for(int&cid=ptr[v];cid<(int)adj[v].size();cid++)
        {
            int id=adj[v][cid];
            int u=edges[id].u;
            if(level[v]+1!=level[u]) continue;
            ll tr=dfs(u,min(pushed,edges[id].cap-edges[id].flow));
            if(tr==0) continue;
            edges[id].flow+=tr;
            edges[id^1].flow-=tr;
            return tr;
        }
        return 0;
    }
    ll flow()
    {
        ll f=0;
        while(true)
        {
            fill(level.begin(),level.end(),-1);
            level[s]=0;
            q.push(s);
            if(!bfs()) break;
            fill(ptr.begin(),ptr.end(),0);
            while(ll pushed=dfs(s,flow_inf))
            {
                f+=pushed;
            }
        }
        return f;
    }
};
