#include <bits/stdc++.h>
using namespace std;
#define ll long long
using cd = complex<double>;
const double PI = acos(-1);
 
void fft(vector<cd> &a, bool invert) {
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (cd &x: a)
            x /= n;
    }
}
 
vector<ll> multiply(vector<ll> const &a, vector<ll> const &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k,n,m;cin>>k>>n>>m;
    vector<ll>a(k+k);
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a[x]++;
    }
    vector<ll>b(k+k);
    for(int i=0;i<m;i++)
    {
        int x;cin>>x;
        b[x]++;
    }
    vector<ll>ans=multiply(a,b);
    for(int i=2;i<=k+k;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
