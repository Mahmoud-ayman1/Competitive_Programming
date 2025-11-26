#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=60;
ll C[N][N]={};
void compinatorics()
{
    C[0][0]=1;
    for(int i=1;i<N;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int o=1;o<i;o++)
        {
            C[i][o]=C[i-1][o-1]+C[i-1][o];
        }
    }
}
ll calc(ll n,ll ones)
{
    ll ret=(__builtin_popcountll(n)==ones),msb=__lg(n);
    for(int i=msb;i>=0&&ones>=0;i--)
    {
        if((n>>i)&1)
        {
            ret+=C[i][ones],ones--;
        }
    }
    return ret;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    compinatorics();
    ll n;cin>>n;
    ll ans=0;
    for(int i=0;i<50;i++)
    {
        ans+=calc(n,i)*i;
    }
    cout<<ans;
    return 0;
}
