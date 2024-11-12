ll msb(ll n)
{
    ll msb=-1;
    while(n>0) 
    {
        n=n/2;
        msb++;
    }
    return msb;
}
//bitwise and of a range datatype ll
ll andRange(ll l,ll r){
    ll ans=0;
    for(ll i=msb(r);i>=0;i--)
    {
        ll la = 1;
        if((l&(la<<i))==(r&(la<<i)))
        {
            ans+=(l&(la<<i));
        }
        else
        {
            break;
        }
    }
    return ans;
}
