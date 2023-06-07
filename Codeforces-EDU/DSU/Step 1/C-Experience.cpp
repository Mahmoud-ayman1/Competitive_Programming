#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll parent[200005],score[200005],group[200005];
ll find(ll i)
{
    if(parent[i]==i)
    {
        return i;
    }
    return find(parent[i]);
}
void merge(ll x,ll y)
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
    group[leader2]+=group[leader1];
    score[leader1]-=score[leader2];
    parent[leader1]=leader2;
}
ll ans(ll x)
{
    if(parent[x]==x)
    {
        return score[x];
    }
    return score[x]+ans(parent[x]);
}
void init()
{
    for(int i=0;i<200005;i++)
    {
        parent[i]=i;
        group[i]=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int n,t;cin>>n>>t;while(t--)
    {
        string s;cin>>s;
        if(s=="add")
        {
            ll a,b;cin>>a>>b;
            ll w=find(a);
            score[w]+=b;
        }
        else if(s=="join")
        {
            ll a,b;cin>>a>>b;
            merge(a,b);
        }
        else
        {
            ll x;cin>>x;
            cout<<ans(x)<<'\n';
        }
    }
    return 0;
}
