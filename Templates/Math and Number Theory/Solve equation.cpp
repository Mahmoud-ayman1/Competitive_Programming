pair<ll,ll> equ(ll a,ll b,ll c)
{
    ll x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 *a);
    ll x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    return {x1,x2};
}
