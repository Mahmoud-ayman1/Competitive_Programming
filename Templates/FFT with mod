#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5,mod=1009;
const long double PI = acos(-1);
typedef complex<double> C;
#define rep(i,a,b)  for(int i = a; i < b; i++)
void fft(vector<C>& a) {
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vector<ll> rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
                // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
                auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
                C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}
vector<ll> conv(const vector<ll> & a, const vector<ll> & b) {
    if (a.empty() || b.empty()) return {};
    vector<ll> res(a.size() + b.size() - 1);
    int L = 32 - __builtin_clz(res.size()), n = 1 << L;
    vector<C> in(n), out(n);
    copy(a.begin(),a.end(), begin(in));
    rep(i,0,b.size()) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i,0,res.size()) res[i] = (mod+(ll)round(imag(out[i]) / (4 * n))) % mod;
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    int f[m+1]={};
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        f[x]++;
    }
    priority_queue<pair<int,vector<ll>>>pq;
    for(int i=0;i<=m;i++)
    {
        if(f[i])
        {
            f[i]%=mod;
            pq.push({-f[i],vector<ll>(f[i]+1,1)});
        }
    }
    while(pq.size()>1)
    {
        auto [a,b]=pq.top();
        pq.pop();
        auto [x,y]=pq.top();
        pq.pop();
        vector<ll>mul=conv(b,y);
        pq.push({-mul.size(),mul});
    }
    cout<<pq.top().second[k];
    return 0;
}
