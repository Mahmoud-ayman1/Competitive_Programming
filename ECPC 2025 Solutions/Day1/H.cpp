#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

struct DSU {
    ll connected;
    vector<ll> par, sz;
    stack<array<ll, 2> > st;

    DSU(ll n) {
        par = sz = vector<ll>(n + 1, 0);
        for (ll i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
        connected = n;
    }

    ll findparent(ll u) {
        if (par[u] == u)return u;
        ll parent = findparent(par[u]);
        //if not rollback, uncomment
        //par[u] = parent;
        return parent;
    }

    ll getsize(ll u) {
        return sz[findparent(u)];
    }

    void unite(ll u, ll v) {
        ll par1 = findparent(u), par2 = findparent(v);

        st.push({-1, -1});
        if (par1 == par2)
            return;

        if (sz[par1] > sz[par2])
            swap(par1, par2);

        st.pop();
        st.push({connected, par1});
        connected--;

        sz[par2] += sz[par1];
        par[par1] = par2;
    }

    void rollback() {
        if (st.size()) {
            auto x = st.top();
            st.pop();
            if (x[0] == -1)return;
            connected = x[0];
            par[x[1]] = x[1];
        }
    }

    bool is_connected(ll u, ll v) {
        return findparent(u) == findparent(v);
    }
};

int main() {
    baraa
    ll t;
    cin >> t;
    while (t--) {
        ll n, mod = 1e9 + 7;
        cin >> n;
        vector<vector<ll> > a(n + 1, vector<ll>(n + 1, 0));
        DSU dsu(n);
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++) {
                cin >> a[i][j];
                for (ll k = 0; k < a[i][j]; k++)
                    dsu.unite(i + k, j + k);
            }
        ll c = dsu.connected, res = 1, cur = 26;
        while (c--) {
            res *= cur;
            res %= mod;
            cur--;
        }
        cout << res << nl;
    }
    return 0;
}
