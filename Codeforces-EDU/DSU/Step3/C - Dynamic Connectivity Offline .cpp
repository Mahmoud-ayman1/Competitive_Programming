#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=6e5+5;
int n,q,sz,ans[N];vector<array<int,2>>ed;vector<vector<int>>seg,add(N),cut(N);
struct dsu
{
    vector<int>parent,group;stack<array<int,5>>st;int comp;
    dsu(){}
    dsu(int n)
    {
        comp=n-1;
        parent=vector<int>(n);
        iota(parent.begin(),parent.end(),0);
        group=vector<int>(n,1);
    }
    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return find(parent[i]);
    }
    bool samegroup(int x,int y)
    {
        return find(x)==find(y);
    }
    void merge(int x,int y)
    {
        int leader1=find(x);
        int leader2=find(y);
        array<int,5>ins={-1,-1,-1,-1,-1};
        st.push(ins);
        if(leader1==leader2) return;
        st.pop();
        if(group[leader1]>group[leader2]) swap(leader1,leader2);
        ins={leader1,parent[leader1],leader2,group[leader2],comp};
        st.push(ins);
        comp--;
        group[leader2]+=group[leader1];
        parent[leader1]=leader2;
    }
    void rollback()
    {
        array<int,5>lst=st.top();
        st.pop();
        if(lst[0]==-1) return;
        comp=lst[4];
        parent[lst[0]]=lst[1];
        group[lst[2]]=lst[3];
    }
    int answer()
    {
        return comp;
    }
    int getsize(int x)
    {
        return group[find(x)];
    }
}d;
void build(int l,int r,int node)
{
    for(auto it:seg[node])
    {
        d.merge(ed[it][0],ed[it][1]);
    }
    if(l==r)
    {
        ans[l]=d.answer();
        for(auto it:seg[node])
        {
            d.rollback();
        }
        return;
    }
    int mid=l+r>>1;
    build(l,mid,2*node+1);
    build(mid+1,r,2*node+2);
    for(auto it:seg[node])
    {
        d.rollback();
    }
}
void update(int l,int r,int node,int lx,int rx,int idx)
{
    if(r<lx||l>rx) return;
    if(l>=lx&&r<=rx)
    {
        seg[node].push_back(idx);
        return;
    }
    int mid=l+r>>1;
    update(l,mid,2*node+1,lx,rx,idx);
    update(mid+1,r,2*node+2,lx,rx,idx);
}
void init()
{
    sz=1;
    while(sz<=q+5) sz<<=1;
    seg=vector<vector<int>>(sz<<1);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    map<array<int,2>,int>mp;
    ed.push_back({0,0});
    vector<int>queries;
    for(int i=1;i<=q;i++)
    {
        char op;cin>>op;
        if(op=='?')
        {
            queries.push_back(i);
        }
        else
        {
            int a,b;cin>>a>>b;
            if(a>b) swap(a,b);
            if(mp.find({a,b})==mp.end())
            {
                ed.push_back({a,b});
                mp[{a,b}]=ed.size()-1;
            }
            int idx=mp[{a,b}];
            if(op=='+')
            {
                add[idx].push_back(i);
            }
            else
            {
                cut[idx].push_back(i);
            }
        }
    }
    for(int i=1;i<ed.size();i++)
    {
        cut[i].push_back(q+1);
    }
    init();
    for(int i=1;i<ed.size();i++)
    {
        for(auto l:add[i])
        {
            int r=*lower_bound(cut[i].begin(),cut[i].end(),l)-1;
            update(0,sz-1,0,l,r,i);
        }
    }
    d=dsu(n+1);
    build(0,sz-1,0);
    for(auto it:queries)
    {
        cout<<ans[it]<<'\n';
    }
    return 0;
}
