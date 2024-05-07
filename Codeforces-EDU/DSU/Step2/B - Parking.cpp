#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
struct dsu{
    int sz;vector<int>parent;
    dsu(int n)
    {
        sz=n;
        parent=vector<int>(n+1);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }
    void merge(int u,int v)
    {
        int leader1=find(u);
        int leader2=find(v);
        if(leader1==leader2) return;
        if(leader1>leader2) swap(leader1,leader2);
        parent[leader1]=leader2;
    }
    bool sameGroup(int u,int v)
    {
        return find(u)==find(v);
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    dsu d(n+2);
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        int par=d.find(x);
        if(par==n+1)
        {
            par=d.find(1);
            d.merge(1,par+1);
        }
        else
        {
            d.merge(par,par+1);
        }
        cout<<par<<' ';
    }
    return 0;
}
