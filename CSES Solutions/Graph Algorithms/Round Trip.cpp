#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,m,vis[N];vector<int>adj[N];stack<int>st;deque<int>ans;
void dfs(int node,int par)
{
    vis[node]=1;
    st.push(node);
    for(auto it:adj[node])
    {
        if(it==par)
        {
            continue;
        }
        if(!vis[it])
        {
            dfs(it,node);
        }
        else
        {
            ans.push_front(it);
            while(st.size()&&st.top()!=it)
            {
                ans.push_front(st.top());
                st.pop();
            }
            ans.push_front(it);
            cout<<ans.size()<<'\n';
            for(auto it:ans)
            {
                cout<<it<<' ';
            }
            exit(0);
            return;
        }
    }
    st.pop();
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
        if(!vis[i])
        {
            dfs(i,i);
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
