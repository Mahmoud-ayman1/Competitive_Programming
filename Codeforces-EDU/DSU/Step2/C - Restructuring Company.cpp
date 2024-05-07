#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
struct dsu{
    int sz;vector<int>p1,p2,group,group2,mx;
    dsu(int n)
    {
        sz=n;
        p1=vector<int>(n+1);
        group=vector<int>(n+1,1);
        group2=group;
        iota(p1.begin(),p1.end(),0);
        mx=p2=p1;
    }
    int find1(int node)
    {
        if(p1[node]==node) return node;
        return find1(p1[node]);
    }
    int find2(int node)
    {
        if(p2[node]==node) return node;
        return find2(p2[node]);
    }
    void merge1(int u,int v)
    {
        int leader1=find1(u);
        int leader2=find1(v);
        if(leader1==leader2) return;
        if(group[leader1]>group[leader2]) swap(leader1,leader2);
        p1[leader1]=leader2;
        group[leader2]+=group[leader1];
    }
    void merge2(int u,int v)
    {
        int leader1=find2(u);
        int leader2=find2(v);
        if(leader1==leader2) return;
        if(group2[leader1]>group2[leader2]) swap(leader1,leader2);
        p2[leader1]=leader2;
        group2[leader2]+=group2[leader1];
        mx[leader2]=max(mx[leader2],mx[leader1]);
    }
    bool sameGroup(int u,int v)
    {
        return find1(u)==find1(v);
    }
    int get(int node)
    {
        return mx[find2(node)];
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    dsu d(n+2);
    while(q--)
    {
        int op,u,v;cin>>op>>u>>v;
        if(op==1)
        {
            d.merge1(u,v);
        }
        else if(op==2)
        {
            for(int i=d.get(u);i<v;i=d.get(i+1))
            {
                d.merge2(i,i+1);
                d.merge1(i,i+1);
            }
        }
        else
        {
            if(d.sameGroup(u,v))
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}
