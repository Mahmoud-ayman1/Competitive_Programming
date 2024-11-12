//ax+by=gcd(a,b)
ll extended_euclid(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll g=extended_euclid(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}
//generate another x and y
pair<ll,ll> Bezouts_identity(ll a,ll b,ll x,ll y,ll any_number)
{
    return {x+any_number*(b/__gcd(a,b)),y-any_number*(a/(__gcd(a,b)))};
}
