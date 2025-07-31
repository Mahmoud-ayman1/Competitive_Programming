#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main() {
    baraa
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        for (ll i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
        }
        if (m < n - 1 or n * (n - 1) / 2 < m) {
            cout << -1 << nl;
            continue;
        }
        m -= (n - 1);
        ll res = 0;
        for (ll i = 2; i <= n; i++)res += 1 + i;
        if (m) {
            priority_queue<array<ll, 3>, vector<array<ll, 3> >, greater<> > pq;
            for (ll i = 2; i < n; i++)
                pq.push({i + i + 1, i, i + 1});
            map<array<ll, 2>, ll> mp;
            while (pq.size()) {
                auto [c, u, v] = pq.top();
                pq.pop();
                if (u > v)swap(u, v);
                if (u == v or u > n or v > n)continue;
                if (mp[{u, v}])continue;
                res += c;
                m--;
                if (m == 0)break;
                mp[{u, v}] = 1;
                pq.push({u + 1 + v, u + 1, v});
                pq.push({u + 1 + v, u, v + 1});
            }
        }
        cout << res << nl;
    }
    return 0;
}
