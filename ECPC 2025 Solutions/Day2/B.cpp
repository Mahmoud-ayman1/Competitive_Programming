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
        ll n, m;
        cin >> n >> m;
        ll odd = (m + 1) / 2, even = m / 2;
        cout << min(n, odd + 2 * even) << nl;
    }
    return 0;
}
