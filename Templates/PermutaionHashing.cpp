#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
std::mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
ll rand(ll l,ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}
struct node{
    ll a,b,c,d,e;
    node():a(0),b(0),c(0),d(0),e(0){}
    node(ll x,ll xx,ll xxx,ll xxxx,ll xxxxx):a(x),b(xx),c(xxx),d(xxxx),e(xxxxx){}
    node operator+(const node&x)
    {
        node w;
        w.a=a+x.a,w.b=b+x.b,w.c=c+x.c,w.d=d+x.d,w.e=e+x.e;
        return w;
    }
    bool operator==(const node&x)
    {
        return a==x.a&&b==x.b&&c==x.c&&d==x.d&&e==x.e;
    }
    void operator+=(const node&x)
    {
        a+=x.a,b+=x.b,c+=x.c,d+=x.d,e+=x.e;
    }
    node operator=(const node&x)
    {
        a=x.a,b=x.b,c=x.c,d=x.d,e=x.e;
        return node(a,b,c,d,e);
    }
};
node f[N],per[N];
void init()
{
    for(int i=1;i<N;i++) f[i]=per[i]=node(rand(1,1e9),rand(1,1e9),rand(1,1e9),rand(1,1e9),rand(1,1e9));
    for(int i=2;i<N;i++) per[i]+=per[i-1];
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        ll s[n+1]={};
        for(int i=1;i<=n;i++) cin>>s[i];
        node pre[n+5],suf[n+5];
        for(int i=1;i<=n;i++) pre[i]=suf[i]=f[s[i]];
        for(int i=2;i<=n;i++) pre[i]+=pre[i-1];
        for(int i=n-1;i>=1;i--) suf[i]+=suf[i+1];
    }
    return 0;
}
