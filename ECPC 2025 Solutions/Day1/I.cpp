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
        ll n, l, k;
        cin >> n >> l >> k;
        ll mxi = 0;
        while (n--) {
            ll x, y;
            cin >> x >> y;
            mxi = max(mxi, x * x + y * y);
        }
        ll res = 0;
        while (l * l < mxi) {
            if (l + k > l * 2) {
                l += k;
            } else l *= 2;
            res++;
        }
        cout << res << nl;
    }
    return 0;
}
