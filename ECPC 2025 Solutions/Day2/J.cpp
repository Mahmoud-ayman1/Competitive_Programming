#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll N = 1e5 + 10;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
ordered_set st[N], st2[N];
ll f[N]{}, prvF[N]{}, mp[N]{}, lst[N];

struct BIT {
    ll n;
    vector<ll> bit;

    BIT(ll x) {
        n = x;
        bit = vector<ll>(n, 0);
    }

    void add(ll idx,ll val) {
        for (; idx < n; idx |= (idx + 1)) {
            bit[idx] += val;
        }
    }

    void add(ll l, ll r, ll val) {
        // YOU will be forced to call get(index) only without get(index, index).
        add(l, val);
        add(r + 1, -val);
    }

    ll get(ll idx) {
        ll res = 0;
        for (; idx >= 0; idx &= (idx + 1), idx--) {
            res += bit[idx];
        }
        return res;
    }

    ll get(ll l,ll r) {
        return get(r) - (l - 1 >= 0 ? get(l - 1) : 0);
    }
};

int main() {
    baraa
    memset(lst, -1, sizeof lst);
    vector<bool> isPrime(N, 1);
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i < N; i++)
        if (isPrime[i])
            for (ll j = 2 * i; j < N; j += i)
                isPrime[j] = 0;
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1), adj[n + 1], in(n + 1), out(n + 1), tree, dp(n + 1);
    for (ll i = 1; i <= n; i++)cin >> a[i];
    auto b = a;
    for (ll i = 2, u, v; i <= n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<void(ll, ll)> dfs0 = [&](ll u, ll p) {
        tree.push_back(u);
        in[u] = tree.size() - 1;
        for (ll v: adj[u])
            if (v != p)
                dfs0(v, u);
        out[u] = tree.size() - 1;
    };
    auto SUBTASK = [&]() {
        BIT bit(tree.size() + 1);
        vector<array<ll, 2> > qu[tree.size() + 1];
        for (ll i = 1; i <= n; i++)
            qu[in[i]].push_back({out[i], i});
        for (ll i = tree.size() - 1; i >= 0; i--) {
            ll node = tree[i];
            if (isPrime[a[node]]) {
                if (lst[a[node]] != -1)
                    bit.add(lst[a[node]], -1);
                bit.add(i, 1);
                lst[a[node]] = i;
            }
            for (auto [r, idx]: qu[i])
                dp[idx] = bit.get(i, r);
        }
        for (ll i = tree.size() - 1; i >= 0; i--)
            lst[a[tree[i]]] = -1;
    };
    dfs0(1, 0);
    SUBTASK();
    for (ll i = 1; i <= n; i++)
        st[a[i]].insert(in[i]), st2[a[i]].insert(in[i]);
    vector<array<ll, 2> > updates;
    set<ll> values;
    const ll BLK = 200;
    while (q--) {
        ll op, u, x;
        cin >> op;
        if (op == 1) {
            cin >> u;
            ll res = dp[u], m = values.size(), id = 0;
            for (ll i: values)
                f[i] = prvF[i] = st2[i].order_of_key(out[u] + 1) - st2[i].order_of_key(in[u]);
            for (ll idx = updates.size() - 1; idx >= 0; idx--) {
                auto [v, x] = updates[idx];
                if (mp[v] or in[v] < in[u] or in[v] > out[u])continue;
                mp[v] = 1;
                f[a[v]]--;
                f[x]++;
            }
            for (ll val: values) {
                if (isPrime[val] and prvF[val] > 0 and f[val] == 0)res--;
                if (isPrime[val] and prvF[val] == 0 and f[val] > 0)res++;
                // cout << val << ' ' << prvF[val] << ' ' << freq << nl;
            }
            cout << res << nl;

            for (ll i: values)f[i] = 0, prvF[i] = 0;
            for (auto [v, x]: updates)
                mp[v] = 0;
        } else if (op == 2) {
            cin >> u >> x;
            auto it = st[x].lower_bound(in[u]);
            cout << (it != st[x].end() and *it <= out[u]) << nl;
        } else {
            cin >> u >> x;
            st[b[u]].erase(in[u]);
            b[u] = x;
            st[b[u]].insert(in[u]);
            updates.push_back({u, x});
            values.insert(x);
            values.insert(a[u]);
        }
        if (updates.size() == BLK) {
            for (ll i = 1; i <= n; i++)
                st2[a[i]].clear();
            for (auto [v, x]: updates)
                a[v] = x;
            SUBTASK();
            for (ll i = 1; i <= n; i++)
                st2[a[i]].insert(in[i]);
            updates.clear();
            values.clear();
        }
    }
    return 0;
}
