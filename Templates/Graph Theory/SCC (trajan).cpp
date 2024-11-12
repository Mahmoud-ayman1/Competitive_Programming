const int N=2e5+5;
int n,m,lowLink[N],dfn[N],timer,comp[N];
vector<int>adj[N];
vector<vector<int>>components;
stack<int>st;
bool in[N],vis[N];
void dfs(int node)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
}
void trajan(int node)
{
    lowLink[node]=dfn[node]=timer++;
    st.push(node);
    in[node]=1;
    for(auto it:adj[node])
    {
        if(dfn[it]==-1)
        {
            trajan(it);
            lowLink[node]=min(lowLink[node],lowLink[it]);
        }
        else if(in[it])
        {
            lowLink[node]=min(lowLink[node],dfn[it]);
        }
    }
    if(lowLink[node]==dfn[node])
    {
        vector<int>component={};
        int x=-1;
        while(x!=node)
        {
            x=st.top();
            st.pop();
            comp[x]=components.size();
            in[x]=0;
            component.push_back(x);
        }
        components.push_back(component);
    }
}
void init()
{
    memset(dfn,-1,sizeof dfn);
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==-1)
        {
            trajan(i);
        }
    }
}
