#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct NTT {
    static const int MAXF = 1 << 20;
    int pr;
    int rts[MAXF + 1];
    int bitrev[MAXF];

    int fpow(int a, int k, int p) {
        if (!k) return 1;
        int res = a, tmp = a;
        k--;
        while (k) {
            if (k & 1) {
                res = (long long) res * tmp % p;
            }
            tmp = (long long) tmp * tmp % p;
            k >>= 1;
        }
        return res;
    }
    void init(int pr, int pw) {
        this->pr = pr;
        int k = 0; while ((1 << k) < MAXF) k++;
        bitrev[0] = 0;
        for (int i = 1; i < MAXF; i++) {
            bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
        }
        pw = fpow(pw, (pr - 1) / MAXF, pr);
        rts[0] = 1;
        for (int i = 1; i <= MAXF; i++) {
            rts[i] = (long long) rts[i - 1] * pw % pr;
        }
    }
    void dft(int a[], int n, int sign) {
        int d = 0; while ((1 << d) * n != MAXF) d++;
        for (int i = 0; i < n; i++) {
            if (i < (bitrev[i] >> d)) {
                swap(a[i], a[bitrev[i] >> d]);
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int delta = MAXF / len * sign;
            for (int i = 0; i < n; i += len) {
                int *x = a + i,*y = a + i + (len >> 1), *w = sign > 0 ? rts : rts + MAXF;
                for (int k = 0; k + k < len; k++) {
                    int z = (long long) *y * *w % pr;
                    *y = *x - z, *x = *x + z;
                    if (*y < 0) *y += pr;
                    if (*x >= pr) *x -= pr;
                    x++, y++, w += delta;
                }
            }
        }
        if (sign < 0) {
            int in = fpow(n, pr - 2, pr);
            for (int i = 0; i < n; i++) {
                a[i] = (long long) a[i] * in % pr;
            }
        }
    }
    void multiply(int a[], int b[], int na, int nb, int c[]) {
        static int fa[MAXF], fb[MAXF];
        int n = na + nb - 1; while (n != (n & -n)) n += n & -n;
        for (int i = 0; i < n; i++) fa[i] = fb[i] = 0;
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        dft(fa, n, 1), dft(fb, n, 1);
        for (int i = 0; i < n; i++) fa[i] = (long long) fa[i] * fb[i] % pr;
        dft(fa, n, -1);
        for (int i = 0; i < n; i++) c[i] = fa[i];
    }
    vector<int> multiply(vector<int> a, vector<int> b) {
        static int fa[MAXF], fb[MAXF], fc[MAXF];
        int na = a.size(), nb = b.size();
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        multiply(fa, fb, na, nb, fc);
        int k = na + nb - 1;
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = fc[i];
        return res;
    }
} ntt;
vector<int>power(vector<int>&I,int n)
{
    if(n==1)
    {
        return I;
    }
    vector<int>ret=power(I,n/2);
    ret=ntt.multiply(ret,ret);
    if(n&1)
    {
        ret=ntt.multiply(ret,I);
    }
    return ret;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    vector<int>f(10);
    while(k--)
    {
        int x;cin>>x;
        f[x]=1;
    }
    ntt.init(998244353,3);
    vector<int>all=power(f,n/2);
    int ans=0;
    for(auto it:all)
    {
        ans+=(1LL*it*it)%998244353;;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
