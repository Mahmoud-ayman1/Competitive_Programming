namespace combinatorics
{
    ll MOD;
    vector<ll> fac,inv,finv;
    ll nCr(ll x,ll y)
    {
        if(x<0||y>x)return(0);
        return(fac[x]*finv[y]%MOD*finv[x-y]%MOD);
    }
    ll power(ll b,ll n)
    {
        b%=MOD;
        ll s=1;
        while(n)
        {
            if(n%2==1)s=s*b%MOD;
            b=b*b%MOD;
            n/=2;
        }
        return s;
    }
    void init(int n,ll mod)
    {
        fac.resize(n+1);
        inv.resize(n+1);
        finv.resize(n+1);
        MOD=mod;
        fac[0]=inv[0]=inv[1]=finv[0]=finv[1]=1;
        for(ll i=1;i<=n;++i)fac[i]=fac[i-1]*i%MOD;
        for(ll i=2;i<=n;++i)inv[i]=MOD-MOD/i*inv[MOD%i]%MOD;
        for(ll i=2;i<=n;++i)finv[i]=finv[i-1]*inv[i]%MOD;
    }
    ll Inv(int x)
    {
        return power(x,MOD-2);
    }
    ll catalan(int n)
    {
        return (nCr(2*n,n)*Inv(n+1))%MOD;
    }
};
using namespace combinatorics;
