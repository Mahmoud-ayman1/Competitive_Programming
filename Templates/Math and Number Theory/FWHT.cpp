#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
template<int MOD>
struct FWHT {
    int fast(int b, int e) {
        int res = 1;
        for (; e; e >>= 1, b = 1ll * b * b % MOD)
            if (e & 1)
                res = 1ll * res * b % MOD;
        return res;
    }

    inline int add(int x, int y) {
        return x + y - (x + y >= MOD ? MOD : 0);
    }

    inline int sub(int x, int y) {
        return x - y + (x - y < 0 ? MOD : 0);
    }

    void FST(vector<int> &a, bool inv) {
        for (int n = (int)a.size(), step = 1; step < n; step *= 2) {
            for (int i = 0; i < n; i += 2 * step)
                for(int j=i;j<i+step;j++) {
                int &u = a[j], &v = a[j + step];
                tie(u, v) =
                        //  inv ? pii(sub(v,u), u) : pii(v, add(u,v)); // AND
                        //  inv ? pii(v, sub(u,v)) : pii(add(u,v), u); // OR /// include-line
                        pair<ll, ll>(add(u, v), sub(u, v));           // XOR /// include-line
            }
        }
        if (inv) {
            int divisor = fast((int)a.size(), MOD - 2);
            for (int &x: a) x = 1ll * x * divisor % MOD; // XOR only /// include-line
        }
    }

    vector<int> conv(vector<int> a, vector<int> b) {
        FST(a, 0);
        FST(b, 0);
        for(int i=0;i<(int)a.size();i++) a[i] = 1ll * a[i] * b[i] % MOD;
        FST(a, 1);
        return a;
    }
};
const int N=2e5+5;
int n,m,w[N],par[N];vector<pair<int,int>>adj[N];vector<vector<int>>component;bool vis[N];
void dfs(int node)
{
    vis[node]=1;
    for(auto [a,b]:adj[node])
    {
        if(!par[a])
        {
            par[a]=node;
            w[a]=b;
            dfs(a);
        }
        else if(vis[a]&&a!=par[node])
        {
            vector<int>comp={b};
            for(int node2=node;node2!=a;node2=par[node2])
            {
                comp.push_back(w[node2]);
            }
            component.push_back(comp);
        }
    }
    vis[node]=0;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int all=0;
    while(m--)
    {
        int a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        all^=c;
    }
    par[1]=1;
    dfs(1);
    FWHT<1000000007>ft1;
    FWHT<1000000009>ft2;
    vector<int>ans(1<<17),ans2(1<<17);
    ans[all]=ans2[all]=1;
    for(auto s:component)
    {
        vector<int>frq(1<<17);
        for(auto it:s)
        {
            frq[it]++;
        }
        ans=ft1.conv(ans,frq);
        ans2=ft2.conv(ans2,frq);
    }
    for(int i=0;i<(1<<17);i++)
    {
        if(ans[i]||ans2[i])
        {
            cout<<i<<' '<<ans[i];
            return 0;
        }
    }
    return 0;
}
