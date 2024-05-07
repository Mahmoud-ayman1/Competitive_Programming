#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
struct dsu{
    int sz;vector<int>parent,group;
    dsu(int n)
    {
        sz=n;
        parent=vector<int>(n+1);
        group=vector<int>(n+1,1);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int node)
    {
        if(parent[node]==node) return node;
        return find(parent[node]);
    }
    void merge(int u,int v)
    {
        int leader1=find(u);
        int leader2=find(v);
        if(leader1==leader2) return;
        if(group[leader1]>group[leader2]) swap(leader1,leader2);
        parent[leader1]=leader2;
        group[leader2]+=group[leader1];
    }
    bool sameGroup(int u,int v)
    {
        return find(u)==find(v);
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    while(m--)
    {
        int a;cin>>a>>a;
    }
    array<int,3>qu[q];
    for(int i=0;i<q;i++)
    {
        string op;int u,v;
        cin>>op>>u>>v;
        if(op=="ask") qu[i]={0,u,v};
        else qu[i]={1,u,v};
    }
    dsu d(n);
    deque<string>ans;
    for(int i=q-1;i>=0;i--)
    {
        auto [op,u,v]=qu[i];
        if(op==0)
        {
            if(d.sameGroup(u,v)) ans.push_front("YES\n");
            else ans.push_front("NO\n");
        }
        else
        {
            d.merge(u,v);
        }
    }
    for(auto it:ans)
    {
        cout<<it;
    }
    return 0;
}
