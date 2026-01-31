#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        vector<int>adj[n+5];
        for(int i=1;i<=n;i++)
        {
            int m;cin>>m;
            while(m--)
            {
                int x;cin>>x;
                adj[x].push_back(i);
            }
        }
        string ans="No";
        for(int a=1;a<=n;a++)
        {
            vector<int>vis(n+1,0);
            queue<int>q;
            q.push(a);
            vis[a]=1;
            while(q.size())
            {
                int node=q.front();
                q.pop();
                for(auto it:adj[node])
                {
                    vis[it]+=vis[node];
                    q.push(it);
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(vis[i]>1)
                {
                    ans="Yes";
                    goto done;
                }
            }
        }
        done:{}
        cout<<ans<<'\n';
    }
    return 0;
}
