#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dsu
{
    vector<int>parent,group;stack<array<int,5>>st;int comp;
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
    void addCheckPoint()
    {
        st.push({-5,-5,-5,-5,-5});
    }
    void undo()
    {
        while(st.size()&&st.top()[0]!=-5)
        {
            rollback();
        }
        st.pop();
    }
    int answer()
    {
        return comp;
    }
    int getsize(int x)
    {
        return group[find(x)];
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    dsu d(n+1);
    while(q--)
    {
        string op;cin>>op;
        if(op=="persist")
        {
            d.addCheckPoint();
        }
        else if(op=="rollback")
        {
            d.undo();
            cout<<d.answer()<<'\n';
        }
        else
        {
            int a,b;cin>>a>>b;
            d.merge(a,b);
            cout<<d.answer()<<'\n';
        }
    }
    return 0;
}
