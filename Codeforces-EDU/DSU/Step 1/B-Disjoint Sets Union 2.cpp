#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300005;
int parent[N],group[N],l[N],h[N];
void init()
{
    for(int i=0;i<N;i++)
    {
        parent[i]=i;
        group[i]=1;
        l[i]=i;
        h[i]=i;
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
        swap(leader1,leader2);
    }
    parent[leader1]=leader2;
    group[leader2]+=group[leader1];
    l[leader2]=min(l[leader1],l[leader2]);
    h[leader2]=max(h[leader1],h[leader2]);
}
int groupsize(int x)
{
    return group[find(x)];
}
int minimal(int x)
{
    return l[find(x)];
}
int maximal(int x)
{
    return h[find(x)];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int t,n;cin>>n>>t;while(t--)
    {
        string s;cin>>s;
        if(s=="union")
        {
            int a,b;cin>>a>>b;
            merge(a,b);
        }
        else
        {
            int x;cin>>x;
            cout<<minimal(x)<<' '<<maximal(x)<<' '<<groupsize(x)<<'\n';
        }
    }
    return 0;
}
