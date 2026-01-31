#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
const int Q=2e5+5;
const int SQ=448;
struct query{
    int l,r,q_idx,block_idx;
    query(){}
    query(int _l,int _r,int _q_idx)
    {
        l=_l,r=_r,q_idx=_q_idx,block_idx=_l/SQ;
    }
    bool operator<(const query&y)const{
        if(block_idx!=y.block_idx)
        {
            return block_idx<y.block_idx;
        }
        return r<y.r;
    }
};
void compress(vector<ll>&a,int start)
{
    int n=a.size();
    vector<pair<ll,ll>>pairs(n);
    for(int i=0;i<n;i++)
    {
        pairs[i]={a[i],i};
    }
    sort(pairs.begin(),pairs.end());
    int nxt=start;
    for(int i=0;i<n;i++)
    {
        if(i>0&&pairs[i-1].first!=pairs[i].first)
        {
            nxt++;
        }
        a[pairs[i].second]=nxt;
    }
}
int n,q,res=0,q_ans[Q],f[N];int mx=0;vector<ll>s;bool z[N];
query queries[Q];
void add(int idx)
{
    if(z[idx]) return;
    res-=f[s[idx]]&1;
    f[s[idx]]++;
    res+=f[s[idx]]&1;
}
void remove(int idx)
{
    if(z[idx]) return;
    res-=f[s[idx]]&1;
    f[s[idx]]--;
    res+=f[s[idx]]&1;
}
void MO_process()
{
    sort(queries,queries+q);
    int l=1,r=0;
    for(int i=0;i<q;i++)
    {
        while(r<queries[i].r)add(++r);
        while(r>queries[i].r)remove(r--);
        while(l<queries[i].l)remove(l++);
        while(l>queries[i].l)add(--l);
        q_ans[queries[i].q_idx]=res;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    s=vector<ll>(n+5);
    int pre[n+5]={};
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]!=0)
        {
            pre[i]=1;
        }
        else
        {
            z[i]=1;
        }
        pre[i]+=pre[i-1];
    }
    compress(s,1);
    int L[q],R[q];
    for(int i=0;i<q;i++)
    {
        int &l=L[i],&r=R[i];cin>>l>>r;
        queries[i]=query(l,r,i);
    }
    MO_process();
    for(int i=0;i<q;i++)
    {
        ll mog=pre[R[i]]-pre[L[i]-1];
        cout<<(mog-q_ans[i])/2+q_ans[i]+(q_ans[i]&1)<<'\n';
    }
    return 0;
}
