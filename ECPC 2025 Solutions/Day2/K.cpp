#include<bits/stdc++.h>
#define ll long long
#define nl endl
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main() {
    baraa
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll &i: a)cin >> i;
        map<ll, ll> used;
        ll res = 0;
        sort(all(a));
        for (ll i = 0; i < n; i++) {
            if (used[a[i]])continue;
            res++;
            ll x = a[i];
            while (x <= 2e9)used[x] = 1, x *= 2;
        }
        cout << res << nl;
    }
    return 0;
}
