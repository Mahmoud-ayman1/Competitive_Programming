ll numberOfDivisors(ll n)
{
    int primes[]={2,3,5,7,11,13,17,19};
    ll num=1,ans=1;
    for (int it:primes)
    {
        int c=0;
        while(n%it==0)
        {
            n/=it;
            c++;
        }
        ans*=c+1;
        num*=it;
    }
    int all=0;
    for(int i=1;i<num;i++)
    {
        bool can=1;
        for (int it:primes)
        {
            if(i%it==0)
            {
                can=0;
            }
        }
        if(can)
        {
            ll o=i;
            for (;o*o<n;o+=num)
            {
                if(n%o==0)
                {
                    all += 2;
                }
            }
            if (o*o==n)
            {
                all++;
            }
        }
    }
    return ans*all;
}
