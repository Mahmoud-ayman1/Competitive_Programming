#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
#define baraa ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll mod = 1e9 + 7;
ll fp(ll a,ll b) {
    ll ans = 1, push = a;
    while (b > 0) {
        if (b & 1) { ans = (ans * push) % mod; }
        push = (push * push) % mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    baraa
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<vector<ll> > a(n, vector<ll>(n, 0));
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                cin >> a[i][j];
        ll mxi = -1e16;
        for (ll black = 0; black <= n; black++) {
            ll white = n - black;
            vector<vector<ll> > dp(n + 2, vector<ll>(n + 2, -1e17));
            function<ll(ll, ll, ll)> solve = [&](ll i, ll j, ll k)-> ll {
                if (i == n)return (j == black ? 0 : (ll) -1e16);
                if (dp[i][j] != (ll) -1e17)return dp[i][j];
                ll op1 = -1e16, op2 = -1e16;
                if (j != black)op1 = solve(i + 1, j + 1, k) + a[i][j];
                if (k != white)op2 = solve(i + 1, j, k + 1) + a[i][black + k];
                return dp[i][j] = max(op1, op2);
            };
            mxi = max(mxi, solve(0, 0, 0));
        }
        cout << mxi << nl;
    }
    return 0;
}
