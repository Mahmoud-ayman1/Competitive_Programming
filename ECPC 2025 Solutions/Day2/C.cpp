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
    int n;cin>>n;
    int s[n+1]={},pre[n+1]={};
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        pre[i]=pre[i-1]+s[i];
    }
    vector<ll>f(1e6+5);
    for(int i=0;i<=n;i++)
    {
        f[pre[i]]++;
    }
    vector<ll>ans=multiply(f,f);
    ll tot=0;
    for(int i=1;i<=n;i++)
    {
        ans[pre[i]+pre[i]]--;
    }
    for(auto&it:ans)
    {
        it/=2;
    }
    for(int i=1;i<=n;i++)
    {
        tot+=ans[pre[i]+pre[i]];
    }
    cout<<tot;
    return 0;
}
