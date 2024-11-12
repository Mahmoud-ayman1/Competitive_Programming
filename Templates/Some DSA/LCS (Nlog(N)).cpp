#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct FenwickTree{
    int N;vector<int>bit;
    FenwickTree(int n,int init=0)
    {
        N=n+1;
        bit=vector<int>(n+1,init);
    }
    void update(int idx,int val)
    {
        while(idx<N)
        {
            bit[idx]=max(bit[idx],val);
            idx+=idx&-idx;
        }
    }
    int query(int idx)
    {
        int ret=0;
        while(idx>0)
        {
            ret=max(ret,bit[idx]);
            idx-=idx&-idx;
        }
        return ret;
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int pos[n+1];
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        pos[x]=i;
    }
    pair<int,int>s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i].first;
        s[i].second=i+1;
    }
    sort(s,s+n,[&](pair<int,int>&i,pair<int,int>&j){
        return pos[i.first]<pos[j.first];
    });
    FenwickTree tree(n);
    for(int i=0;i<n;i++)
    {
        int pre=tree.query(s[i].second);
        tree.update(s[i].second,pre+1);
    }
    cout<<tree.query(n);
    return 0;
}
