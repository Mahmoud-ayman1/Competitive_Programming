const int N=2e5+5;
int n,m,lowLink[N],dfn[N],timer,comp[N],root[N],_2satCom[N],_2sat[N];
vector<int>adj[N];
vector<vector<int>>components;
stack<int>st;
bool in[N],vis[N];
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
        root[comp[node]]=node;
    }
}
void init()
{
    memset(dfn,-1,sizeof dfn);
    memset(_2satCom,-1,sizeof _2satCom);
    for(int i=1;i<=n+n;i++)
    {
        if(dfn[i]==-1)
        {
            trajan(i);
        }
    }
}
int Not(int x)
{
    return 2*n-x+1;
}
bool solve_2Sat()
{
    for(int i=1;i<=n;i++)
    {
        if(comp[i]==comp[Not(i)])
        {
            return 0;
        }
    }
    return 1;
}
void assignVals()
{
    for(int i=0;i<components.size();i++)
    {
        if(_2satCom[i]==-1)
        {
            _2satCom[i]=1;
            _2satCom[comp[Not(root[i])]]=0;
        }
    }
    for(int i=1;i<=n+n;i++)
    {
        _2sat[i]=_2satCom[comp[i]];
    }
}
void addOr(int a,int b)
{
    adj[Not(a)].push_back(b);
    adj[Not(b)].push_back(a);
}
