#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105;
int mat[N];vector<int>adj[N];bool vis[N];
bool can_match(int node)
{
    if(vis[node]) return 0;
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(mat[it]==-1||can_match(mat[it]))
        {
            mat[it]=node;
            return 1;
        }
    }
    return 0;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    set<int>st;map<string,int>idx;int c=1;
    for(int i=0;i<q;i++)
    {
        string a,b;cin>>a>>b;
        if(idx[a]==0) idx[a]=c++;
        if(idx[b]==0) idx[b]=c++;
        adj[idx[a]].push_back(idx[b]);
        st.insert(idx[a]);
    }
    memset(mat,-1,sizeof mat);
    int ans=0;
    for(auto it:st) memset(vis,0,sizeof vis),ans+=can_match(it);
    cout<<ans;
    return 0;
}
// https://codeforces.com/gym/103800/problem/J
