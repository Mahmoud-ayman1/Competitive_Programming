const int N=5000006;
ll phi[N];
void sieve()
{
    for(int i=0;i<N;i++)
    {
        phi[i]=i;
    }
    for(int i=2;i<N;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<N;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}


ll phi(ll n)
{
    ll ret=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)n/=i;
            ret-=ret/i;
        }
    }
    if(n>1) ret-=ret/n;
    return ret;
}
