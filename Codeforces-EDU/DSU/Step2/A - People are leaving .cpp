#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
struct dsu{
    int sz;vector<int>parent,group,mx;
    dsu(int n)
    {
        sz=n;
        parent=vector<int>(n+1);
        group=vector<int>(n+1,1);
        iota(parent.begin(),parent.end(),0);
        mx=parent;
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
        mx[leader2]=max(mx[leader2],mx[leader1]);
    }
    bool sameGroup(int u,int v)
    {
        return find(u)==find(v);
    }
    int get(int node)
    {
        return mx[find(node)];
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    dsu d(n+2);
    while(q--)
    {
        char op;cin>>op;
        if(op=='?')
        {
            int idx;cin>>idx;
            int ans=d.get(idx);
            if(ans>n)
            {
                cout<<-1<<'\n';
            }
            else
            {
                cout<<ans<<'\n';
            }
        }
        else
        {
            int idx;cin>>idx;
            d.merge(idx,idx+1);
        }
    }
    return 0;
}
