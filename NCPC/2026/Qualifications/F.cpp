#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dsu
{
    vector<int>parent,group;
    dsu(int n)
    {
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
        if(leader1==leader2) return;
        if(group[leader1]>group[leader2]) swap(leader1,leader2);
        group[leader2]+=group[leader1];
        parent[leader1]=leader2;
    }
    int getsize(int x)
    {
        return group[find(x)];
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        dsu d(n+5);
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                d.merge(i,i+1);
            }
        }
        vector<deque<int>>v={{}};
        bool vis[n+5]={};
        for(int i=0;i<n;i++)
        {
            int pr=d.find(i);
            if(vis[pr]) continue;
            vis[pr]=1;
            int cnt=d.getsize(pr);
            if(cnt!=1&&cnt!=2&&cnt!=4)
            {
                v.push_back(deque<int>());
            }
            if(cnt==1||cnt==2||cnt==4)
            {
                v.back().push_back(cnt);
            }
        }
        for(auto&it:v)
        {
            while(it.size()&&(it.front()%2==0||it.back()%2==0))
            {
                if(it.back()%2==0) it.pop_back();
                if(it.size()&&it.front()%2==0) it.pop_front();
            }
        }
        for(auto it:v)
        {
            if(it.size()>1)
            {
                cout<<"NO\n";
                goto done;
            }
        }
        cout<<"YES\n";
        done:{}
    }
    return 0;
}
