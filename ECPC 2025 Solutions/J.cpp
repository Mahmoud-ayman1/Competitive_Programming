#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
#define all(v) v.begin(),v.end()
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main() {
    baraa
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i: a)cin >> i;
    vector<ll> pref(n), suf(n), prv(n, -1), nxt(n, n + 1);
    for (ll i = 0; i < n; i++) {
        if (i)pref[i] = pref[i - 1];
        pref[i] = max(pref[i], a[i]);
    }
    for (ll i = n - 1; i >= 0; i--) {
        if (i + 1 < n)suf[i] = suf[i + 1];
        suf[i] = max(suf[i], a[i]);
    }
    stack<pair<ll, ll> > st;
    for (ll i = 0; i < n; i++) {
        while (st.size() and st.top().first < a[i])st.pop();
        if (st.size())prv[i] = st.top().second;
        st.push({a[i], i});
    }
    while (st.size())st.pop();
    for (ll i = n - 1; i >= 0; i--) {
        while (st.size() and st.top().first < a[i])st.pop();
        if (st.size())nxt[i] = st.top().second;
        st.push({a[i], i});
    }
    ll res = LLONG_MAX;
    for (ll i = 1; i + 1 < n; i++) {
        ll p = max(0LL, prv[i]), p2 = min(n - 1, nxt[i]);
        res = min(res, a[i] + pref[p] + suf[p2]);
    }
    cout << res;
    return 0;
}
