#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct DSU
{
    int parent[200005];
    int group[200005];
    DSU()
    {
        for(int i=0;i<200005;i++)
        {
            parent[i]=i;
            group[i]=1;
        }
    }
    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return parent[i]= find(parent[i]);
    }
    bool samegroup(int x,int y)
    {
        return find(x)==find(y);
    }
    void merge(int x,int y)
    {
        int leader1=find(x);
        int leader2=find(y);
        if(leader1==leader2)
        {
            return;
        }
        if(group[leader1]>group[leader2])
        {
            parent[leader2]=leader1;
            group[leader1]+=group[leader2];
        }
        else
        {
            parent[leader1]=leader2;
            group[leader2]+=group[leader1];
        }
    }
    int getsize(int x)
    {
        return group[find(x)];
    }
};
int main()
{
    DSU d;
    int t,n;cin>>n>>t;while(t--)
    {
        string s;int a,b;
        cin>>s>>a>>b;
        if(s=="union")
        {
            d.merge(a,b);
        }
        else
        {
            if(d.samegroup(a,b))
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
