#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=505,OO=1e18;
int n,m,cap[N][N];vector<int>par,adj[N];
 
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, OO});
 
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
 
        for (int next : adj[cur]) {
            if (parent[next] == -1 && cap[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
 
    return 0;
}
 
int maxFlow(int s, int t) {
    int flow = 0;
    vector<int> parent(n+5);
    int new_flow;
 
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }
 
    return flow;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b]+=c;
    }
    cout<<maxFlow(1,n);
    return 0;
}
