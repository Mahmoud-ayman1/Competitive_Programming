bool is_perfect_square(ll x)
{
    ll y = (ll)sqrtl(x);
    while(y * y < x) y++;
    while(y * y > x) y--;
    return x == y * y;
}
