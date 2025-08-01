#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll N = 1e6 + 10;
ll fact[N], inv[N], mod = 1e9 + 7;
ll fp(ll a,ll b) {
    ll ans = 1, push = a;
    while (b > 0) {
        if (b & 1) { ans = (ans * push) % mod; }
        push = (push * push) % mod;
        b >>= 1;
    }
    return ans;
}

void FacInv() {
    fact[0] = inv[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = ((i % mod) * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2) % mod; //use i if you want the mod inverse of i itself
    }
}

ll nCr(ll n,ll r) {
    if (n < r)return 0;
    return (fact[n] % mod * (inv[r] % mod * inv[n - r] % mod) % mod) % mod;
}

ll nPr(ll n,ll r) {
    return (fact[n] % mod * (inv[n - r]) % mod) % mod;
}

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
    FacInv();
    ll n, M = 20;
    cin >> n;
    vector<ll> a(n);
    vector<BIT> segs(M, BIT(n));
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        for (ll bit = 0; bit < M; bit++)
            if (a[i] >> bit & 1)
                segs[bit].add(i, 1);
    }
    ll q;
    cin >> q;
    while (q--) {
        ll op, l, r, k, x, idx;
        cin >> op;
        if (op == 2) {
            cin >> idx >> x;
            idx--;
            for (ll bit = 0; bit < M; bit++)
                if (a[idx] >> bit & 1)
                    segs[bit].add(idx, -1);
            a[idx] = x;
            for (ll bit = 0; bit < M; bit++)
                if (a[idx] >> bit & 1)
                    segs[bit].add(idx, 1);
        } else {
            cin >> l >> r >> k;
            l--, r--;
            ll ans = 0;
            for (ll bit = 0; bit < M; bit++) {
                ll zeroes = r - l + 1 - segs[bit].get(l, r);
                ll ways = (nCr(r - l + 1, k) - nCr(zeroes, k) + mod) % mod;
                // cout << bit << ' ' << zeroes << ' ' << ways << nl;
                ans = (ans + (ways * (1LL << bit)) % mod) % mod;
            }
            cout << ans << nl;
        }
    }
    return 0;
}
